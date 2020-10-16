# 整数的划分

def f(q, n, m):
    count = 0
    if len(q) == 0:
        print(str(n))
        count = 1
    for i in range(1, n + 1):
        if (i <= n - i <= m):
            print(q + str(n - i) + "+" + str(i))
            count += 1
        if (0 < n - i <= m):
            count += f(q + str(n - i) + "+", i, n - i)
    return count
            

num = int(input("整数： "))
print("划分数量为: ", f("", num, num))
