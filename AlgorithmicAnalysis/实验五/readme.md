输入
    m: 棋盘x轴大小
    n: 棋盘Y轴大小
    x: 马一开始的坐标x
    y: 马一开始的坐标x

马的走法(共8个方向):
dt_x=[1,1,2,2,-1,-1,-2-2]
dt_y=[2,-2,1,-1,2,-2,1,-1]

1. 从起始点，按照马的8个方向尝试走
2. 注意边界的判断
3. 记录遍历(走)过得点

