X = X1 * X2 * X3…..Xn-1*Xn
那么用Y[n-1,a]表示X1 * X2 * X3…..Xn-1 相乘的值为a的序列，那么同理: 
Y[n-1,b]表示X1 * X2 * X3…..Xn-1 相乘的值为b; 
Y[n-1,c]表示X1 * X2 * X3…..Xn-1 相乘的值为c
同等转化为:X= (Y[n-1,a] + Y[n-1,b]+ Y[n-1,c])* Xn,子问题就是对于求出n’=n-1时，Y[n-1,a] 、Y[n-1,b]、 Y[n-1,c]，
  令v[x,y]表示，以x(x in [a,b,c])为乘数，乘上某一乘数后得出y(y in [a,b,c])，容易跟所给的表算出矩阵v[x,y]
  ans =  sum((Y[n-1,a] + Y[n-1,b]+ Y[n-1,c])* Xn),
  	  = sum(Y[n-1,a]*Xn + Y[n-1,b]*Xn + Y[n-1,c]*Xn ) //不是数值上得乘
	  = Y[n-1,a]*v[a,a]+ Y[n-1,b]*v[b,a]+ Y[n-1,b]*v[b,a]   //数值上的乘

