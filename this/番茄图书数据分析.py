# -*- coding: utf-8 -*-
import requests
import plotly.express as px
from bs4 import BeautifulSoup
import time
import plotly.io as pio
import pandas as pd

# 禁用浏览器打开，只保存文件
pio.renderers.default = "svg"

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"
}

book_data = []

print("正在爬取 番茄小说网 排行榜...\n")

# 尝试爬取番茄小说网
try:
    # 爬取多个页面以获取足够的数据
    base_url = "https://fanqienovel.com"
    page_count = 5  # 爬取5个页面
    total_books = 0
    
    for page in range(1, page_count + 1):
        if page == 1:
            url = base_url
        else:
            url = f"{base_url}/library/all/page_{page}?sort=hottes"
        
        print(f"爬取第 {page} 页: {url}")
        resp = requests.get(url, headers=headers, timeout=10)
        resp.encoding = resp.apparent_encoding
        soup = BeautifulSoup(resp.text, "html.parser")
        
        # 提取小说链接（更广泛的选择器）
        novel_links = soup.find_all('a', href=lambda href: href and '/page/' in href and len(href) > 20)
        
        # 也尝试从其他地方提取小说
        divs = soup.find_all('div', class_=lambda x: x and ('novel' in x or 'book' in x or 'item' in x))
        for div in divs:
            links = div.find_all('a', href=lambda href: href and '/page/' in href)
            novel_links.extend(links)
        
        # 去重
        seen_hrefs = set()
        unique_links = []
        for link in novel_links:
            href = link.get('href')
            if href and href not in seen_hrefs:
                seen_hrefs.add(href)
                unique_links.append(link)
        novel_links = unique_links
        
        print(f"  找到 {len(novel_links)} 个小说链接")
        
        for i, link in enumerate(novel_links):
            text = link.text.strip()
            if text and len(text) > 0 and len(text) < 50:  # 过滤过长的文本
                # 解析书名和作者
                parts = text.split()
                if len(parts) >= 2:
                    title = ' '.join(parts[:-1])
                    author = parts[-1]
                else:
                    title = text
                    author = "未知作者"
                
                # 根据排名计算评分（排名越靠前，评分越高）
                rank_num = total_books + i + 1
                # 评分范围从 6 到 10，1分为一个单位
                score = 10 - (rank_num - 1) // 5  # 每5个排名降1分
                score = max(6, score)
                
                book_data.append({
                    "排名": rank_num,
                    "书名": title, 
                    "作者": author,
                    "评分": score, 
                    "来源": f"第{page}页"
                })
                
                total_books += 1
        
        time.sleep(1.5)  # 增加延迟，避免被反爬
    
    print(f"\n  爬取完成！共：{total_books} 本小说")
    
    if total_books == 0:
        raise Exception("未获取到任何小说数据")
    
except Exception as e:
    print(f"爬取失败：{e}")
    print("将使用真实数据格式的模拟数据...\n")
    
    # 如果没有爬取到数据，使用模拟数据（模拟真实数据格式）
    import random
    random.seed(42)  # 固定随机种子，保证每次运行结果一致
    
    # 生成小说数据
    authors = ["天蚕土豆", "唐家三少", "辰东", "忘语", "耳根", "我吃西红柿", "乱", "江南", "天下霸唱", "南派三叔"]
    genres = ["玄幻", "都市", "历史", "科幻", "悬疑", "言情", "武侠", "奇幻"]
    
    # 生成20-50本小说
    total_books = random.randint(20, 50)
    for i in range(total_books):
        # 生成随机标题
        title = f"{random.choice(genres)}小说{i+1}"
        author = random.choice(authors)
        
        # 根据排名计算评分
        rank_num = i + 1
        score = 10 - (rank_num - 1) // 5
        score = max(6, score)
        
        book_data.append({
            "排名": rank_num,
            "书名": title, 
            "作者": author,
            "评分": score, 
            "来源": "模拟数据"
        })
    
    print(f"模拟数据生成完成！共：{total_books}本小说")

# 创建DataFrame用于分析
df = pd.DataFrame(book_data)

# 按评分区间分组并计算排名
score_ranks = {}
for score in sorted(df['评分'].unique(), reverse=True):
    score_books = df[df['评分'] == score].sort_values('排名')
    score_ranks[score] = score_books.to_dict('records')

print("\n  评分区间排名：")
for score in sorted(score_ranks.keys(), reverse=True):
    books = score_ranks[score]
    print(f"\n{score} 分：共 {len(books)} 本")
    for i, book in enumerate(books, 1):
        print(f"  {i}. {book['书名']} - {book['作者']} (总排名: {book['排名']})")

# ==========================
#  重新布局：评分区间排名仪表盘
# ==========================
import plotly.graph_objects as go
from plotly.subplots import make_subplots

# 准备评分区间数据
score_distribution = df['评分'].value_counts().sort_index(ascending=False)
score_categories = score_distribution.index.tolist()
score_counts = score_distribution.values.tolist()

# 创建新的仪表盘布局（3x2 网格）
fig_dashboard = make_subplots(
    rows=3, cols=2,
    subplot_titles=(
        "评分区间分布（饼图）",
        "评分区间数量（柱状图）",
        "评分趋势（折线图）",
        "评分区间占比（水平柱状图）",
        "小说评分散点图",
        "评分区间排名表"
    ),
    specs=[
        [{"type": "pie"}, {"type": "bar"}],
        [{"type": "scatter"}, {"type": "bar"}],
        [{"type": "scatter"}, {"type": "table"}]
    ]
)

# 1. 饼图：评分区间分布
fig_dashboard.add_trace(
    go.Pie(
        labels=[f"{score} 分" for score in score_categories],
        values=score_counts,
        hole=0.3,
        textposition="inside",
        textinfo="percent+label",
        hovertemplate="<b>%{label}</b><br>数量：%{value} 本<br>占比：%{percent}",
        marker=dict(
            colors=px.colors.qualitative.Pastel
        )
    ),
    row=1, col=1
)

# 2. 柱状图：评分区间数量
fig_dashboard.add_trace(
    go.Bar(
        x=[f"{score}" for score in score_categories],
        y=score_counts,
        marker=dict(
            color=px.colors.qualitative.Pastel
        ),
        hovertemplate="评分：%{x} 分<br>数量：%{y} 本"
    ),
    row=1, col=2
)

# 3. 折线图：评分趋势
fig_dashboard.add_trace(
    go.Scatter(
        x=df['排名'],
        y=df['评分'],
        mode="lines+markers",
        line=dict(color="#1f77b4", width=2),
        marker=dict(size=6, color="#1f77b4"),
        hovertemplate="排名：%{x}<br>评分：%{y} 分"
    ),
    row=2, col=1
)

# 4. 水平柱状图：评分区间占比
fig_dashboard.add_trace(
    go.Bar(
        y=[f"{score} 分" for score in score_categories],
        x=[count/len(df)*100 for count in score_counts],
        orientation="h",
        marker=dict(
            color=px.colors.qualitative.Pastel
        ),
        hovertemplate="评分：%{y}<br>占比：%{x:.2f}%"
    ),
    row=2, col=2
)

# 5. 散点图：小说评分分布
fig_dashboard.add_trace(
    go.Scatter(
        x=df['排名'],
        y=df['评分'],
        mode="markers",
        marker=dict(
            size=8,
            color=df['评分'],
            colorscale="Viridis",
            colorbar=dict(title="评分")
        ),
        hovertemplate="<b>%{text}</b><br>排名：%{x}<br>评分：%{y} 分<br>作者：%{customdata}",
        text=df['书名'],
        customdata=df['作者']
    ),
    row=3, col=1
)

# 6. 表格：评分区间排名
# 准备表格数据
table_data = []
for score in sorted(score_ranks.keys(), reverse=True):
    books = score_ranks[score]
    for i, book in enumerate(books, 1):
        table_data.append([
            f"{score} 分",
            i,
            book['书名'],
            book['作者'],
            book['排名'],
            book['来源']
        ])

fig_dashboard.add_trace(
    go.Table(
        header=dict(
            values=["评分区间", "区间排名", "书名", "作者", "总排名", "来源"],
            fill_color="paleturquoise",
            align="left"
        ),
        cells=dict(
            values=list(zip(*table_data)),
            fill_color="lavender",
            align="left"
        )
    ),
    row=3, col=2
)

# 更新布局
fig_dashboard.update_layout(
    title={
        'text': "番茄小说网 评分区间排名分析仪表盘",
        'font': {
            'size': 24,
            'family': 'Arial',
            'color': '#333'
        },
        'x': 0.5,
        'xanchor': 'center'
    },
    height=1200,
    width=1200,
    showlegend=False,
    hovermode="closest",
    plot_bgcolor="#f9f9f9",
    paper_bgcolor="#ffffff",
    margin={
        'l': 50,
        'r': 50,
        't': 150,
        'b': 50
    }
)

# 更新坐标轴标签和样式
fig_dashboard.update_xaxes(
    title={
        'text': "评分区间",
        'font': dict(size=12, color='#333')
    }, 
    row=1, col=2,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0'
)
fig_dashboard.update_yaxes(
    title={
        'text': "小说数量",
        'font': dict(size=12, color='#333')
    }, 
    row=1, col=2,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0'
)

fig_dashboard.update_xaxes(
    title={
        'text': "排名",
        'font': dict(size=12, color='#333')
    }, 
    row=2, col=1,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0'
)
fig_dashboard.update_yaxes(
    title={
        'text': "评分",
        'font': dict(size=12, color='#333')
    }, 
    row=2, col=1,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0',
    range=[5.5, 10.5]
)

fig_dashboard.update_xaxes(
    title={
        'text': "占比 (%)",
        'font': dict(size=12, color='#333')
    }, 
    row=2, col=2,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0'
)

fig_dashboard.update_xaxes(
    title={
        'text': "排名",
        'font': dict(size=12, color='#333')
    }, 
    row=3, col=1,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0'
)
fig_dashboard.update_yaxes(
    title={
        'text': "评分",
        'font': dict(size=12, color='#333')
    }, 
    row=3, col=1,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0',
    range=[5.5, 10.5]
)

# 优化子图标题样式
fig_dashboard.update_annotations(
    font=dict(size=14, color='#333', family='Arial')
)

# ==========================
#  导出功能
# ==========================

# 保存图表为 HTML 文件，可以使用此文件打开文件夹
html_file = "番茄小说网评分区间排名分析仪表盘.html"
fig_dashboard.write_html(html_file)
print(f"\n图表已保存为 HTML 文件：{html_file}")

# 提示信息
print("\n使用说明：")
print("1. 打开生成的 HTML 文件可以查看交互式仪表盘")
print("2. 点击图表元素可以查看详细信息")
print("3. 悬停在散点图上可以查看小说详细信息")
print("4. 使用图表右上角的导出按钮可以下载图表")
print("5. 表格显示了每个评分区间的排名情况")
