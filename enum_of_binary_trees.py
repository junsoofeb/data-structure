#  t[n]은 n개의 노드로 만들 수 있는 binary tree의 개수

t = [0 for i in range(101)] # 길이 101짜리 리스트 생성

t[0] = t[1] = 1 


for n in range(2, 101, 1):
    for i in range(1, n+1, 1):
      t[n] += t[i - 1] * t[n - i]

print("t[100] = ", t[100]) # 100개의 노드로 만들 수 있는 binary tree의 개수 출력