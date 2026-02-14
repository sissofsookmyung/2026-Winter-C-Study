from collections import deque

n = int(input()) #자연수 하나 입력 받음

discarded = [] #버리는 카드 넣을 리스트

queue = deque(range(1, n + 1)) #큐에 1~n 카드 넣기

while len(queue) > 1: #언제까지? 큐에 하나만 남을 때까지
    discarded.append(queue.popleft()) #큐에서 하나 꺼내서(선입선출) 리스트에 추가
    queue.append(queue.popleft()) #큐에서 하나 꺼내서 다시 큐에 추가

result = discarded + list(queue) #큐에 남은 수를 리스트에 합침 
print(*result) #원소 한 칸씩 띄어서 전부 출력