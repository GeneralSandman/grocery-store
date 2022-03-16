#!/bin/bash


# 通过 docsify 渲染

# 通过 cos-bucket website 功能部署


# coscmd config -a sid  -s skey -b zhenhuli-blog-1252697766 -r ap-beijing
coscmd upload -r ./ / --ignore "./.git/*"

#--ignore "./.git/*,./leetcode/leetcode-crawler/*"%

echo "open https://zhenhuli-blog-1252697766.cos-website.ap-beijing.myqcloud.com\n"
echo "open http://zhenhuli.ring.wiki\n"