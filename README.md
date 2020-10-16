# 备考PAT的刷题记录

[TOC]

## 数据结构与算法题目集

### 7-6 列出连通集

+ 递归DFS 非递归BFS
@import "DSA_7_6.c" {code_block=true class="line-numbers"}

+ 非递归DFS 非递归BFS
   1. 因为使用了非递归的算法，栈中或许会多次压入某个节点，**判断是否访问，确保栈的大小，防爆栈**
   2. 题目要求从小向大访问节点，**非递归算法需自大向小压栈**
//@import "DSA_7_6_2.c" {code_block=true class="line-numbers"}

### 7-7 六度空间

+ floyd
   1. 计算任意两点间的距离，计算小于等于6的节点占比
   2. 通过**对称**优化运算
//@import "DSA_7_7.c" {code_block=true class="line-numbers"}

+ BFS(待尝试)

### 7-8 哈利·波特的考试

+ floyd
   1. 节点：动物，路径权重：魔咒长度
   2. 出现INF则有不可到达节点
   3. 筛选部分可同时计算最`复杂动物`与`携带动物`，减少循环
//@import "DSA_7_8.c" {code_block=true class="line-numbers"}

### 7-9 旅游规划

+ Dijkstr
   1. 计算某点到其他点距离
   2. 注意路径相同时**价格的更新**
@import "DSA_7_9.cpp" {code_block=true class="line-numbers"}

### 7-10 公路村村通

+ Prim
   1. 使用Prim算法更容易判断树的存在，既非联通图
   2. 注意边界，节点1-N,但是边集从头遍历
@import "DSA_7_10.cpp" {code_block=true class="line-numbers"}

### 7-11 关键活动

+ AOE图关键路径算法(点集+边集)
   临接矩阵， 十字链表也行
   1. 输出顺序
   2. 多起点，多终点情况下，终点最晚需要为全局最晚
//@import "DSA_7_11.cpp" {code_block=true class="line-numbers"}

### 7-13 统计工龄

+ 链表
+ 平衡树
+ 散列表

### 7-17 汉诺塔的非递归实现

