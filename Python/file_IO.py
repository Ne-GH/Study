#! /usr/bin/python3

# coding=utf-8

in_file = open("./Test.in","r")
print("文件名:",in_file.name)

str = in_file.read()
print("read nums:",str)


in_file.close()

