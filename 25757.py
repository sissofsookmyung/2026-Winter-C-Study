import sys

input = sys.stdin.readline

n, game_type = input().split() #게임 신청한 사람 수, 게임 종류 입력
n = int(n)

#경우의 수 Y F O 중 Y면 (본인 제외 인원인인)1명, F면 2명, O면 3명 뽑아야 함
if game_type == 'Y':
    required = 1
elif game_type == 'F':
    required = 2
else:  # 'O'
    required = 3

players = set() #중복 없이 set 자료구조에 이름 저장
for _ in range(n):
    name = input().strip()
    players.add(name)

print(len(players) // required) #set의 크기(=등록된 사람 수)를 1,2,3으로 나눈 몫이 출력 결과임