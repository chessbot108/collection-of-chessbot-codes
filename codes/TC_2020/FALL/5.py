#miles

x = int(input())
for i in range(x):
    a = input()
    x = a.split(" ")
    a = x[0]
    b = x[1]
    print(bin(int(b,int(a)))[2:])
