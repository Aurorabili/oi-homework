# The 2023 ICPC Asia EC Online (I)

## A Qualifiers Ranking Rules 
The following is the current ranking rules for the ICPC Asia EC Online Qualifiers, and there will be two online contests.

1.	In each contest, only the rank of the top-ranked team from each university will be taken as the score of that university;
2.	In each contest, participating universities will be ranked according to their scores;
3.	The two rankings of universities are combined using the merge sorting method. For any two universities that obtain the same ranking in different contests, the university that received this ranking in the first contest will be ranked first.
4.	Delete duplicate universities and obtain the final ranking of all participating universities (only the highest rankings for each university are retained).

Now assuming that there are n teams in the first contest and m teams in the second contest.

For each contest, given the ranking of each team and the university to which it belongs, please output the final ranking of all participating universities according to the above rules.

You can better understand this process through the sample.

### Input
The first line contains two integers n,m (1≤n,m≤104) , representing the number of teams participating in the first contest and the second contest.

Then following n lines, the i-th line contains a string si (1≤∣si∣≤10) only consisting of uppercase letters, representing the abbreviation of the university to which the i-th ranked team in the first contest belongs.

Then following m lines, the i-th line contains a string ti (1≤∣ti∣≤10) only consisting of uppercase letters, representing the abbreviation of the university to which the i-th ranked team in the second contest belongs.

It’s guaranteed that each university has only one abbreviation.

### Output
Output several lines, the i-th line contains a string, representing the abbreviation of the i-th ranked university in the final ranking.

You should ensure that the abbreviation of any participating universities appears exactly once.

### Input Sample
```
14 10
THU
THU
THU
THU
XDU
THU
ZJU
THU
ZJU
THU
NJU
WHU
THU
HEU
PKU
THU
PKU
PKU
ZJU
NUPT
THU
NJU
CSU
ZJU
```
### Output Sample
```
THU
PKU
XDU
ZJU
NJU
NUPT
WHU
HEU
CSU
```
### Hint
Sample is part of the results in 2022 ICPC Asia EC Online Contest.
In the first contest, the ranking of the universities is:
```
THU
XDU
ZJU
NJU
WHU
HEU
```

In the second contest, the ranking of the universities is:
```
PKU
THU
ZJU
NUPT
NJU
CSU
```

By combining these two rankings according to the rules, the rankings of the universities is:
```
THU
PKU
XDU
THU
ZJU
ZJU
NJU
NUPT
WHU
NJU
HEU
CSU
```

By deleting duplicate universities we will get the final ranking.

**代码长度限制**
16 KB
**时间限制**
1000 ms
**内存限制**
128 MB

## B String

Given two strings S1 and S2 of equal length (indexed from 1).

Now you need to answer q queries, with each query consists of a string T.

The query asks how many triplets of integers (i,j,k) (1≤i≤j<k≤∣S1∣) satisfy the condition S1[i,j]+S2[j+1,k]=T.

Here S[l,r] denotes the substring of S with index form l to r, and "+" denotes concatenation of strings.

### Input
The first line contains a string S1 .

The second line contains a string S2 .

It is guaranteed that 1≤∣S1∣=∣S2∣≤105.

The third line contains a positive integer q (1≤q≤2×105), representing the number of queries.

The next q lines each contain a string T (1≤∣T∣≤2×105), representing the query strings.

It is guaranteed that ∑∣T∣≤2×105 and all the strings input only consisting of lowercase letters.

### Output
For each query, output a line with a positive integer representing the number of triplets that satisfy the condition.

### Input Sample
```
aaababaa
aababbca
7
aa
abb
aab
ab
abc
bb
ba
```

### Output Sample
```
3
1
3
2
2
1
0
```

**代码长度限制**
16 KB
**时间限制**
1000 ms
**内存限制**
256 MB

## C Multiply Then Plus

Given n pairs (a1,b1),(a2,b2),…,(an,bn), you need to perform q operations.
Each operation has one of the following forms:

- 1 k a b (1≤k≤n, 1≤a,b≤109): Modify the k-th pair into (a,b).
- 2 x l r (1≤x≤109, 1≤l≤r≤n): Find the maximum value of ai×x+bi, where l≤i≤r.

### Input

The first line contains two integers n and q (1≤n,q≤500000) denoting the number of pairs and the number of operations.

Each of the following n lines contains two integers ai and bi (1≤ai,bi≤109), denoting the i-th pair.

Each of the next q lines describes an operation in the format shown above.

### Output
For each query, print a single line containing an integer denoting the answer.

### Input Sample 
```
3 5
2 3
1 5
3 1
2 1 1 3
2 3 1 2
1 3 1 1
2 3 3 3
2 2 1 3
```

### Output Sample 
```
6
9
4
7
```

**代码长度限制**
16 KB
**时间限制**
6000 ms
**内存限制**
1024 MB

## D Transitivity

Given a simple undirected graph with n vertices and m edges, and it’s guaranteed that m<(1/2)*n(n−1) .
We define an undirected graph to be transitive if and only if for any two different vertices u,v :
If there exists a path starting from u and ending at v in the graph, then there should exists an edge connected u and v in the graph.
Now you should add some undirected edges to the graph (add at least one edge). You need to ensure that after adding edges, the graph is still a simple undirected graph and is transitive.
The question is, how many edges need to be added at least?
Recall that a simple undirected graph is an undirected graph that does not have more than one edge between any two vertices and no edge starts and ends at the same vertex.

### Input
The first line contains two integers n,m (3≤n≤106,1≤m≤min(106,1/2*(n(n−1))−1)), indicating the number of vertices and edges in the given graph.
Then the following m lines, each line contains two integers u,v (1≤u,v≤n,u!=v) , indicating an edge in the given graph. It's guaranteed that the graph is simple.
Output
A single positive integer, representing the minimum number of edges you need to add.
### Input Sample
```
4 3
1 2
1 3
2 3
```
### Output Sample
```
3
```
**代码长度限制**
16 KB
**时间限制**
1000 ms
**内存限制**
128 MB

## E Magical Pair

For a prime number n, if a pair of positive integers (x,y) satisfies the congruence relation: x_y≡y_x(modn). Then we consider (x,y) to be magical.
We want to know how many ordered pairs of positive integers (x,y) are magical for a given prime number n, where 0<x,y≤n2−n. Since the answer could be large, we will output it modulo 998244353.
Input
The first line input a positive integer T (1≤T≤10), which represents the total number of test cases.
Then for each test case, input a single line with a prime number n (2≤n≤1018), and it’s guaranteed that n−1 is not a multiple of 998244353.
Output
Output T lines, each containing an integer representing the result modulo 998244353.
### Input Sample 1
```
5
5
11
67
97
101
```
### Output Sample 1
```
104
1550
479886
1614336
1649000
```
### Input Sample 2
```
6
998244353
998244853
19260817
1000000007
1000000009
350979772330483783
```
### Output Sample 2
```
284789646
90061579
971585925
887008006
527110672
334479293
```
**代码长度限制**
16 KB
**时间限制**
1000 ms
**内存限制**
512

## F Alice and Bob

You are watching Alice and Bob playing a game.
The game is played on an array of length n. Alice and Bob take turns in action, Alice goes first.

In each turn, the current player can select two different numbers ai and aj in the array, and then change their values. Assume after changes the values of them are ai′ and aj′ , then an operation is legal if and only if ai+aj=ai′+aj′ and ∣ai′−aj′∣<∣ai−aj∣. Those who cannot perform legal operations lose.

After playing a few games, You decided to help Alice, because Alice, who was always overloaded when faced with a bunch of numbers, always unable to think in front of the genius Bob.

Before the start of each game, You will help Alice remove several numbers (could be 0) to reduce the burden on her brain, and you always leave exactly three numbers. And in order to give Alice a greater chance of winning, You will always leave Alice with a winning state, that is, there must be some kind of operating strategy that makes Alice must win no matter how Bob acts.
Now the question is how many ways there are to remove the numbers.

Two ways for removing numbers are considered different if and only if there exists an integer i (1≤i≤n) such that ai is not removed in one way and is removed in the other way.

### Input
The first line contains a single integer T , representing the number of test cases.
Then follow the descriptions of each test case.
The first line contains an integer n(3≤n≤5×105) , which represents the number of numbers at the beginning.
The second line contains n integers a1,a2,a3,…,an(0≤ai≤1018), representing the original n numbers.
It's guaranteed that ∑n≤3×106 .
### Output
For each test case, output one integer in one line, indicating the number of different ways to remove numbers that satisfy the condition.
### Input Sample
```
3
4
2 0 2 3
3
2 2 3
3
0 2 3
```
### Output Sample
```
3
0
1
```
### Hint
In the first test case, only removing a2 leaves a loser state.
**代码长度限制**
16 KB
**时间限制**
3000 ms
**内存限制**
512 MB

## G Spanning Tree

We generate a spanning tree of n nodes according to the following random process:

Initially, there are no edges connecting the n nodes.

Then process the following n−1 operations:
- For the i-th operation, two integers ai and bi will be input, and it’s guaranteed that the two nodes are not connected before.
- Select a node ui from the connected block where ai is located with uniform probability, then select a node vi from the connected block where bi is located with uniform probability, and then add an edge to connect ui and vi .

It can be proved that no matter which two nodes are selected in each operation, after all operations are processed, a spanning tree of n nodes will be formed.

Now given a spanning tree of n nodes. What is the probability that the spanning tree formed by the random process is exactly this spanning tree?

You only need to output the value of the probability modulo 998244353 .

Please note that the probability could be 0, which means that you can never generate this spanning tree.

### Input
The first line contains a single integer n (1≤n≤106) , representing the number of nodes.
For the following n−1 lines, each line contains two integers a_i,b_i (1≤a_i,b_i≤n,a_i!=b_i), representing the i-th operation, and it’s guaranteed that the two nodes are not connected before.
For the following n−1 lines, each line contains two integers c_i,d_i (1≤c_i,d_i≤n,c_i!=d_i), representing an edge of the given spanning tree, and it’s guaranteed that the given edges forms a spanning tree.

### Output
One line containing one integer, representing the value of the probability modulo 998244353 .
### Input Sample
```
3
1 2
1 3
1 2
1 3
```
### Output Sample
```
499122177
```
**代码长度限制**
16 KB
**时间限制**
1000 ms
**内存限制**
256 MB

## H Range Periodicity Query

For a string w=w1w2…wlen, we say that an integer p is a period of w if wi=wi+p holds for all i (1≤i≤len−p) and 1≤p≤len.

You will be given a string d=d1d2…dn to generate n+1 strings S0,S1,S2,…,Sn, where S0 is an empty string, and for all i (1≤i≤n) :

- When di is a lowercase English letter, Si=di+Si−1.
- When di is an uppercase English letter, assume its lowercase version is ci, then Si=Si−1+ci.

Here, ''+'' denotes concatenation of strings.

You will then be given a sequence of integers p1,p2,…,pm. You need to answer q queries, in each query, you will be given three integers k, l and r. You need to find the minimum number among pl,pl+1,…,pr−1,pr such that it is a period of string Sk, or determine there is no answer.

### Input
The first line contains a single integer n (1≤n≤500000) denoting the number of non-empty strings.
The second line contains a string d of length n consists of lowercase and uppercase English letters.
The third line contains a single integer m (1≤m≤500000) denoting the length of the sequence p.
The fourth line contains m integers p1,p2,…,pm (1≤pi≤n).
The fifth line contains a single integer q (1≤q≤500000) denoting the number of queries.
Each of the next q lines contains three integers k, l and r (1≤k≤n, 1≤l≤r≤m), denoting a query.
### Output
For each query, print a single line containing an integer denoting the answer. Note that when there is no answer, please print -1 instead.
### Input Sample
```
7
AABAAba
9
4 3 2 1 7 5 3 6 1
6
1 4 4
2 1 4
2 1 3
3 3 5
5 4 7
7 8 9
```
### Output Sample
```
1
1
2
-1
3
6
```
**代码长度限制**
16 KB
**时间限制**
2000 ms
**内存限制**
1024 MB

## I Pa?sWorD

You need to log into a mysterious system, but you realize you've forgotten your password. The system does not support resetting password, so the only way to log in is to keep trying.

Fortunately, you still remember some information about the password:

Firstly, you are sure that the length of the password is n .

Then the information you remember can be described by a string s of length n.

let si represent the i-th character of s :

- if si is an uppercase letter or a digital character, then the i-th character of the password must be si;
- if si is an lowercase letter, then the i-th character of the password might be si or the uppercase form of si;
- if si is a question mark ? , then the i-th character of the password might be any uppercase letters, lowercase letters, and digital characters.

It's guaranteed that the string s only contains uppercase letters, lowercase letters, digital characters, and question marks ?.

In addition, the system also has several requirements for passwords:
- At least one uppercase letter appears in the password;
- At least one lowercase letter appears in the password;
- At least one digital character appears in the password;
- Any two adjacent characters in the password cannot be the same.

Now you want to know, how many possible passwords are there? A possible password should fits both your memory and the system's requirements, and it’s guaranteed that there exists at least one possible password.

You know that this answer will be very large, so you just need to calculate the result modulo 998244353 .

Please note the unusual memory limit.

### Input
The first line contains a single integer n (3≤n≤105) , representing the length of the password .
The second line contains a string s with length n. It's guaranteed that the string s only contains uppercase letters, lowercase letters, digital characters, and question marks ?.
It’s guaranteed that there exists at least one possible password.
### Output
output a single line containing a single integer, representing the answer modulo 998244353.
### Input Sample
```
4
a?0B
```
### Output Sample
```
86
```
**代码长度限制**
16 KB
**时间限制**
1000 ms
**内存限制**
32 MB

## J Minimum Manhattan Distance

Recall that on a two-dimensional plane, the Manhattan distance between two points (x1,y1) and (x2,y2) is ∣x1−x2∣+∣y1−y2∣, and the Euclidean distance between two points (x1,y1) and (x2,y2) is (x1−x2)2+(y1−y2)2. If both coordinates of a point are all integers, then we call this point an integer point.

Given two circles C1,C2 on the two-dimensional plane, and guaranteed the x-coordinates of any point in C1 and any point in C2 are different, and the y-coordinates of any point in C1 and any point in C2 are different.

Each circle is described by two integer points, and the segment connecting the two points represents a diameter of the circle.

Now you need to pick a point (x0,y0) inside or on the C2 such that minimize the expected value of the Manhattan distance from (x0,y0) to a point inside C1 , if we choose this point with uniformly probability among all the points with a real number coordinate inside C1.

### Input
The first line contains a single integer t (1≤t≤105) , representing the number of test cases.
Then follow the descriptions of each test case.
The first line contains 4 integers x1,1,y1,1,x1,2,y1,2, representing the segment connecting (x1,1,y1,1) and (x1,2,y1,2) is a diameter of the circle C1.
The second line contains 4 integers x2,1,y2,1,x2,2,y2,2, representing the segment connecting (x2,1,y2,1) and (x2,2,y2,2) is a diameter of the circle C2.
All the coordinates input are integers in the range [−105,105] .
### Output
For each test case, output a single line with a real number - the minimum expected Manhattan distance. Your answer will be considered correct if its absolute or relative error does not exceed 10−6. That is, if your answer is a, and the jury's answer is b, then the solution will be accepted if max(1,∣b∣)∣a−b∣≤10−6 .
### Input Sample
```
1
0 0 2 1
4 5 5 2
```
### Output Sample
```
4.2639320225
```
**代码长度限制**
16 KB
**时间限制**
1000 ms
**内存限制**
64 MB

## K Minimum Euclidean Distance

One day you are surviving in the wild. After a period of exploration, you determine a safe area, which is a convex hull with n vertices P1,P2,…,Pn in counter-clockwise order and any three of them are not collinear.

Now you are notified that there will be q airdrop supplies, and for the i-th supply, its delivery range is described by a circle Ci , which means the supply will landed with uniformly probability among all the points with a real number coordinate inside Ci.

You need supplies so much that you decide to predetermine a starting point for each supply, and the starting point of two different supplies can be different. Every starting point should be inside the safe area and have the smallest expected value of the square of the Euclidean distance to the corresponding supply landing point.

Recall that On a two-dimensional plane, the Euclidean distance between two points (x1,y1) and (x2,y2) is (x1−x2)2+(y1−y2)2. If both coordinates of a point are all integers, then we call this point an integer point.

### Input
The first line contains two integers n,q (3≤n,q≤5000) , representing the number of vertices of the safe area and the number of airdrop supplies.
The following n lines, each line contains two integers xi,yi , representing the coordinates of the i-th vertex of the safe area.
It’s garanteed that the vertices are given in counter-clockwise order and any three of them are not collinear.
Then the following q lines, each line contains 4 integers xi,1,yi,1,xi,2,yi,2, representing the segment connecting (xi,1,yi,1) and (xi,2,yi,2) is a diameter of the circle Ci.
All the coordinates input are integers in the range [−109,109] .

### Output
For each airdrop supply, output a single line with a real number - the minimum expected value of the square of the Euclidean distance. Your answer will be considered correct if its absolute or relative error does not exceed 10−4. That is, if your answer is a, and the jury's answer is b, then the solution will be accepted if max(1,∣b∣)∣a−b∣≤10−4 .

### Input Sample
```
4 3
0 0 
1 0
1 1
0 1
0 0 1 1
1 1 2 2
1 1 2 3
```
### Output Sample
```
0.2500000000
0.7500000000
1.8750000000
```
**代码长度限制**
16 KB
**时间限制**
2000 ms
**内存限制**
128 MB

## L KaChang!

Setting the time limit for algorithm competition questions is a very skillful task. If you set the time limit too tight, many people will scold you for being too demanding on details. On the other hand, if you set the time limit too loosely and allow an algorithm with unexpected time complexity to pass, then many people will scold you too.

When preparing problems, people usually set the time limit to at least twice the running time of the standard program, but sometimes contestants still feel that the time limit is too tight.

Now you have the standard program for a problem and another n programs considered "should pass the problem". Given the running time of each program, please find the smallest integer k≥2, so that when the time limit is set to k times the running time of the standard program, all the provided programs can pass. A program can pass if and only if its running time less or equal to the time limit.

### Input
The first line contains two integers n,T (1≤n,T≤105), representing the number of provided programs (not include the standard program), and the running time of the standard program.
The second line contains n integers t1,t2,…,tn (1≤ti≤109) , representing the running time of the provided programs.
### Output
Output a single integer greater or equal to 2, representing the minimin k which could guarantee that all the provided programs can pass.
### Input Sample
```
5 1000
998 244 353 1111 2333
```
### Output Sample
```
3
```
**代码长度限制**
16 KB
**时间限制**
1000 ms
**内存限制**
128 MB

