import requests
from bs4 import BeautifulSoup

# 爬取番茄小说网
url = "https://fanqienovel.com"
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"
}

resp = requests.get(url, headers=headers)
resp.encoding = resp.apparent_encoding
soup = BeautifulSoup(resp.text, "html.parser")

print("网站标题:", soup.title.text)
print("\n=== 分析网站结构 ===")

# 查找所有带有 class 的 div
print("\n带有 class 的 div 数量:", len(soup.find_all('div', class_=True)))

# 查找包含特定关键词的元素
keywords = ["榜", "排行", "热门", "推荐"]
for keyword in keywords:
    print(f"\n包含 '{keyword}' 的元素:")
    elements = soup.find_all(string=lambda text: text and keyword in text)
    for i, element in enumerate(elements[:5]):  # 最多显示5个
        print(f"  {i+1}. {element.strip()}")
        # 显示父元素
        parent = element.parent
        if parent:
            print(f"     父元素: {parent.name}")
            if parent.get('class'):
                print(f"     父元素 class: {parent['class']}")

# 查找所有链接
print("\n=== 所有链接 ===")
links = soup.find_all('a')
print(f"链接总数: {len(links)}")
print("\n前15个链接:")
for i, link in enumerate(links[:15]):
    text = link.text.strip()
    href = link.get('href', '')
    if text:
        print(f"  {i+1}. {text} -> {href}")

# 查找包含小说标题的元素
print("\n=== 查找小说标题 ===")
title_elements = soup.find_all('a', href=lambda href: href and '/page/' in href)
print(f"找到 {len(title_elements)} 个小说链接")
print("\n前10个小说标题:")
for i, link in enumerate(title_elements[:10]):
    text = link.text.strip()
    href = link.get('href', '')
    if text:
        print(f"  {i+1}. {text} -> {href}")
