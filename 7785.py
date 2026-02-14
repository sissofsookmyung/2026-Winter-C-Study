import sys

input = sys.stdin.read().split() #프로그램에 입력된 모든 내용을 공백 기준으로 잘라 하나의 리스트에 저장
n = int(input[0]) #처음 입력받은 수는 출입 기록 개수
logs = input[1:] #나머지는 로그로 다룸

status = {}

for i in range(0, len(logs), 2): #logs에 key랑 value값이 한꺼번에 들어가 있으니까 2씩 증가시킴
    name = logs[i]
    onoff = logs[i+1]

    status[name] = onoff #딕셔너리에 데이터 등록하거나 출퇴근 상태 업데이트

onduty = [] #출근한 직원 리스트

for name, onoff in status.items(): #key, value 꺼내서
    if onoff == "enter":    #value==enter면 
        onduty.append(name) #출근리스트에 key추가

onduty.sort(reverse=True) #역순 정렬

for o in onduty:
    print(o)