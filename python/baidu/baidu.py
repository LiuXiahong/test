# coding=utf-8
import os
import re
import urllib
import urllib.request
from urllib.parse import quote

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.67 Safari/537.36",
    "referer": "https://image.baidu.com"
}
print("****************************************************************************************")
keyword = input("请输入要下载的图片：")
last_dir = "C://Users//86151//Pictures//Saved Pictures"
dir = "C://Users//86151//Pictures//Saved Pictures//" + keyword
if os.path.exists(last_dir):
    if os.path.exists(dir):
        print("文件夹已经存在")
    else:
        os.mkdir(dir)
        print(dir + "已经创建成功")
else:
    os.mkdir(last_dir)
    if os.path.exists(dir):
        print("文件夹已经存在")
    else:
        os.mkdir(dir)
        print(dir + "已经创建成功")
keyword1 = quote(keyword, encoding="utf-8")
url = "http://image.baidu.com/search/index?tn=baiduimage&ps=2&ct=201326592&lm=-1&cl=2&nc=1&ie=utf-8&word=" + keyword1
req = urllib.request.Request(url, headers=headers)
f = urllib.request.urlopen(req).read().decode("utf-8")
key = r'thumbURL":"(.+?)"'
key1 = re.compile(key)
num = 0
for string in re.findall(key1, f):
    print("正在下载" + string)
    f_req = urllib.request.Request(string, headers=headers)
    f_url = urllib.request.urlopen(f_req).read()
    fs = open(dir + "/" + keyword + str(num) + ".jpg", "wb+")
    fs.write(f_url)
    fs.close()
    num += 1
    print(string + "已下载成功")
input("按任意键结束程序：")
