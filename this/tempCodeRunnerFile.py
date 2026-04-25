# -*- coding: utf-8 -*-
import requests
import plotly.express as px
from bs4 import BeautifulSoup
import time
import plotly.io as pio

# 禁用浏览器打开，只保存文件
pio.renderers.default = "svg"

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"
}

book_data = []

score_count = {
    "9.5分以上": 0,
    "9.0 ~ 9.4分": 0,
    "8.5 ~ 8.9分": 0,
    "8.0 ~ 8.4分": 0,
    "7.5 ~ 7.9分": 0,
    "7.0 ~ 7.4分": 0,
    "6.5 ~ 6.9分": 0,
    "6.5分以下": 0
}

print("正在爬取 豆瓣图书 Top250...\n")

# 只爬取前10页，减少执行时间
for page in range(0, 10):
    url = f"https://book.douban.com/top250?start={page*25}"
    resp = requests.get(url, headers=headers)
    soup = BeautifulSoup(resp.text, "html.parser")

    items = soup.find_all("tr", class_="item")
    for item in items:
        title = item.find("div", class_="pl2").a.get_text(strip=True).replace("\n", "")
        score = float(item.find("span", class_="rating_nums").text)
        info = item.find("p", class_="pl").text

        book_data.append({"书名": title, "评分": score, "信息": info})

        s = score
        if s >= 9.5:
            score_count["9.5分以上"] += 1
        elif 9.0 <= s <= 9.4:
            score_count["9.0 ~ 9.4分"] += 1
        elif 8.5 <= s <= 8.9:
            score_count["8.5 ~ 8.9分"] += 1
        elif 8.0 <= s <= 8.4:
            score_count["8.0 ~ 8.4分"] += 1
        elif 7.5 <= s <= 7.9:
            score_count["7.5 ~ 7.9分"] += 1
        elif 7.0 <= s <= 7.4:
            score_count["7.0 ~ 7.4分"] += 1
        elif 6.5 <= s <= 6.9:
            score_count["6.5 ~ 6.9分"] += 1
        else:
            score_count["6.5分以下"] += 1

    time.sleep(1)
    print(f"第 {page+1} 页完成")

print("\n  爬取完成！共：", len(book_data), "本图书")
print("\n  评分分布：")
for k, v in score_count.items():
    print(f"{k}：{v} 本")

# ==========================
#  统一仪表盘布局
# ==========================
import plotly.graph_objects as go
from plotly.subplots import make_subplots

# 准备数据
categories = list(score_count.keys())
counts = list(score_count.values())

# 创建仪表盘布局（2x2网格）
fig_dashboard = make_subplots(
    rows=2, cols=2,
    subplot_titles=(
        "豆瓣图书 Top250 评分分布（圆环图）",
        "各评分区间图书数量对比（柱状图）",
        "评分分布散点图",
        "评分区间占比"
    ),
    specs=[
        [{"type": "pie"}, {"type": "bar"}],
        [{"type": "scatter"}, {"type": "bar"}]
    ]
)

# 添加圆环图
fig_dashboard.add_trace(
    go.Pie(
        labels=categories,
        values=counts,
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

# 添加柱状图
fig_dashboard.add_trace(
    go.Bar(
        x=categories,
        y=counts,
        marker=dict(
            color=px.colors.qualitative.Pastel
        ),
        hovertemplate="评分：%{x}<br>数量：%{y} 本"
    ),
    row=1, col=2
)

# 解析图书信息，提取作者、出版社、出版年份等详细信息
def parse_book_info(info):
    # 尝试从信息字符串中提取作者、出版社、出版年份等信息
    parts = info.split("/")
    if len(parts) >= 3:
        author = parts[0].strip()
        publisher = parts[-3].strip() if len(parts) >= 3 else "未知"
        year = parts[-2].strip() if len(parts) >= 2 else "未知"
        price = parts[-1].strip() if len(parts) >= 1 else "未知"
        return f"作者：{author}<br>出版社：{publisher}<br>出版年份：{year}<br>价格：{price}"
    return f"信息：{info}"

# 添加散点图（显示每本书的评分分布）
scores = [book["评分"] for book in book_data]
titles = [book["书名"] for book in book_data]
book_details = [parse_book_info(book["信息"]) for book in book_data]

fig_dashboard.add_trace(
    go.Scatter(        x=lis\nt(range(len(book_data))),
        y=scores,
        mode="markers",
        marker=dict(
            size=8,
            color=scores,
            colorscale="Viridis",
            colorbar=dict(title="评分")
        ),
        hovertemplate="<b>%{text}</b><br>评分：%{y}<br>%{customdata}",
        text=titles,
        customdata=book_details
    ),
    row=2, col=1
)

# 添加评分区间占比图
fig_dashboard.add_trace(
    go.Bar(
        x=categories,
        y=[v/len(book_data)*100 for v in counts],
        marker=dict(
            color=px.colors.qualitative.Pastel
        ),
        hovertemplate="评分：%{x}<br>占比：%{y:.2f}%"
    ),
    row=2, col=2
)

# 添加评分范围筛选控件
fig_dashboard.update_layout(
    title={
        'text': "豆瓣图书 Top250 数据分析仪表盘",
        'font': {
            'size': 20,
            'family': 'Arial',
            'color': '#333'
        },
        'x': 0.5,
        'xanchor': 'center'
    },
    height=900,
    width=1100,
    showlegend=False,
    hovermode="closest",
    plot_bgcolor="#f9f9f9",
    paper_bgcolor="#ffffff",
    margin={
        'l': 50,
        'r': 50,
        't': 120,
        'b': 50
    },
    updatemenus=[
        dict(
            type="dropdown",
            direction="down",
            buttons=list([
                dict(
                    args=[{"visible": [True, True, True, True]}],
                    label="全部评分",
                    method="update"
                ),
                dict(
                    args=[{"visible": [True, True, [s >= 9.0 for s in scores], True]}],
                    label="9.0分以上",
                    method="update"
                ),
                dict(
                    args=[{"visible": [True, True, [8.0 <= s < 9.0 for s in scores], True]}],
                    label="8.0-8.9分",
                    method="update"
                ),
                dict(
                    args=[{"visible": [True, True, [7.0 <= s < 8.0 for s in scores], True]}],
                    label="7.0-7.9分",
                    method="update"
                ),
                dict(
                    args=[{"visible": [True, True, [s < 7.0 for s in scores], True]}],
                    label="7.0分以下",
                    method="update"
                )
            ]),
            pad={"r": 10, "t": 10},
            showactive=True,
            x=0.1,
            xanchor="left",
            y=1.1,
            yanchor="top",
            bgcolor="#f0f0f0",
            bordercolor="#ccc",
            borderwidth=1
        )
    ],
    # 添加动画效果
    transition={'duration': 500, 'easing': 'cubic-in-out'}
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
        'text': "图书数量",
        'font': dict(size=12, color='#333')
    }, 
    row=1, col=2,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0'
)
fig_dashboard.update_xaxes(
    title={
        'text': "图书索引",
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
    range=[6, 10]  # 设置评分范围
)
fig_dashboard.update_xaxes(
    title={
        'text': "评分区间",
        'font': dict(size=12, color='#333')
    }, 
    row=2, col=2,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0'
)
fig_dashboard.update_yaxes(
    title={
        'text': "占比 (%)",
        'font': dict(size=12, color='#333')
    }, 
    row=2, col=2,
    tickfont=dict(size=10, color='#666'),
    gridcolor='#e0e0e0'
)

# 优化子图标题样式
fig_dashboard.update_annotations(
    font=dict(size=14, color='#333', family='Arial')
)

# ==========================
#  图表联动功能
# ==========================

# 添加图表联动功能
def update_dashboard(trace, points, selector):
    # 获取点击的索引
    if points.point_inds:
        selected_index = points.point_inds[0]
        selected_category = categories[selected_index]
        
        # 清除所有高亮
        for i, trace in enumerate(fig_dashboard.data):
            if hasattr(trace, 'marker') and hasattr(trace.marker, 'opacity'):
                fig_dashboard.data[i].marker.opacity = 1
            if hasattr(trace, 'opacity'):
                fig_dashboard.data[i].opacity = 1
        
        # 高亮柱状图对应的数据
        if trace.type == 'pie':
            # 点击了饼图，高亮柱状图对应的数据
            fig_dashboard.data[1].marker.opacity = [0.3 if i != selected_index else 1 for i in range(len(counts))]
            fig_dashboard.data[3].marker.opacity = [0.3 if i != selected_index else 1 for i in range(len(counts))]
            
            # 高亮散点图中对应评分区间的点
            score_range = selected_category
            min_score, max_score = 0, 0
            if score_range == "9.5分以上":
                min_score = 9.5
            elif score_range == "9.0 ~ 9.4分":
                min_score, max_score = 9.0, 9.4
            elif score_range == "8.5 ~ 8.9分":
                min_score, max_score = 8.5, 8.9
            elif score_range == "8.0 ~ 8.4分":
                min_score, max_score = 8.0, 8.4
            elif score_range == "7.5 ~ 7.9分":
                min_score, max_score = 7.5, 7.9
            elif score_range == "7.0 ~ 7.4分":
                min_score, max_score = 7.0, 7.4
            elif score_range == "6.5 ~ 6.9分":
                min_score, max_score = 6.5, 6.9
            else:  # 6.5分以下
                max_score = 6.5
            
            # 高亮散点图中对应评分区间的点
            opacities = []
            for score in scores:
                if score_range == "9.5分以上":
                    opacities.append(1 if score >= min_score else 0.3)
                elif score_range == "6.5分以下":
                    opacities.append(1 if score < max_score else 0.3)
                else:
                    opacities.append(1 if min_score <= score <= max_score else 0.3)
            fig_dashboard.data[2].marker.opacity = opacities
    
# 为饼图添加点击事件
fig_dashboard.data[0].on_click(update_dashboard)

# 为柱状图添加点击事件
fig_dashboard.data[1].on_click(update_dashboard)

# 为散点图添加点击事件
def show_book_details(trace, points, selector):
    if points.point_inds:
        selected_index = points.point_inds[0]
        book = book_data[selected_index]
        print(f"\n图书详情：")
        print(f"书名：{book['书名']}")
        print(f"评分：{book['评分']}")
        print(f"信息：{book['信息']}")

fig_dashboard.data[2].on_click(show_book_details)

# ==========================
#  导出功能
# ==========================

# 保存图表为HTML文件，可以使用此文件打开文件夹
html_file = "豆瓣图书分析仪表盘.html"
fig_dashboard.write_html(html_file)
print(f"\n图表已保存为HTML文件：{html_file}")

# 提示信息
print("\n使用说明：")
print("1. 打开生成的HTML文件可以查看交互式仪表盘")
print("2. 点击图表元素可以查看详细信息")
print("3. 使用顶部下拉菜单可以按评分范围筛选数据")
print("4. 悬停在散点图上可以查看图书详细信息")
print("5. 点击散点图上的点可以在控制台查看图书详情")
print("6. 使用图表右上角的导出按钮可以下载图表")