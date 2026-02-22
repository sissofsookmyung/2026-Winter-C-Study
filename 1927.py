import sys

# 입력을 빠르게 받기 위한 설정
input = sys.stdin.read

class heap:
    #힙 초기 설정
    def __init__(self):
        self.size = 0
        self.heap = [None]
    
    def isEmpty(self): 
        return self.size == 0
    
    #힙 추가 연산
    def add_heap(self, num):
        self.heap.append(num)
        self.size += 1
        idx = self.size

        #idx가 1보다 클 경우 트리를 돌면서 추가하는 숫자의 자리를 찾아줌
        while idx > 1:
            parent = idx // 2

            #부모가 더 큰 경우 현재 숫자와 부모의 자리를 바꿔줌
            if self.heap[idx] < self.heap[parent]:
                self.heap[idx], self.heap[parent] = self.heap[parent], self.heap[idx]
                idx = parent
            else:
                break

    #힙 삭제 연산
    def del_heap(self):
        if self.isEmpty(): 
            return 0
        
        #촤소 힙이므로 첫 번째 요소가 가장 작음. 그걸 root로 꺼내옴
        root = self.heap[1]

        #마지막 요소를 꺼내와 root로 보냄
        last = self.heap.pop()
        self.size -= 1

        if self.size > 0:
            self.heap[1] = last
            parent = 1
            child = 2

            #트리를 돌면서 자식 노드가 트리 사이즈와 같아질 때까지 비교 연산을 통해 root친구의 자리를 찾아줌
            while child <= self.size:

                #두 명의 자식 중 더 작은 자식을 찾음
                if child + 1 <= self.size and self.heap[child+1] < self.heap[child]:
                    child += 1
                
                #부모가 자식보다 더 작을 경우는 그냥 넘어가고 아닌 경우는 부모 <-> 자식 자리를 바꿔줌
                if self.heap[parent] <= self.heap[child]: 
                    break
                self.heap[parent], self.heap[child] = self.heap[child], self.heap[parent]
                parent = child
                child = parent * 2
            
        return root

def main():
    # 모든 입력을 한 번에 읽어와 공백 단위로 나눔
    data = input().split()
    if not data:
        return
    
    n = int(data[0])
    h = heap()
    
    # 출력할 결과값들을 리스트에 모아서 한 번에 출력
    results = []

    for i in range(1, n + 1):
        num = int(data[i])
        if num == 0:
            results.append(str(h.del_heap()))
        else:
            h.add_heap(num)

    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()