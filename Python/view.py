#多图绘制
#导入包numpy
import numpy as np
#定义一维数组
t = np.arange(0, 5, 0.2)


#使用数组同时绘制多个线性

#线条1
x1=y1=t
#线条2
x2=x1
y2=t**2
#线条3
x3=x1
y3=t**3
#使用plot绘制线条
linesList=plt.plot(x1, y1,x2, y2,x3,y3)
#用setp方法可以同时设置多个线条的属性
plt.setp(linesList, color='r')
plt.show()
print('返回的数据类型',type(linesList))
print('数据大小：',len(linesList))
