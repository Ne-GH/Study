#! /usr/bin/bash

read -p "请输入一个文件名，及路径，用以判断是否为文件" file
test -f &file
	if [ $? -eq 0 ]; then
		echo "是文件"
		exit;
	else 
		echo "不是文件"
	fi
