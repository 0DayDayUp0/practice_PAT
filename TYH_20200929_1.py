# 所有合法括号匹配

q = []
def f(str, n):
    if str in q:
        return
    if n == 0:
        q.append(str)
        return  
    f("(" + str + ")", n -1)
    f(str + "()", n -1)
    f("()" + str , n -1)

f("", int(input()))
print("\n".join(q))