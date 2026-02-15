

def how(many, box) :

     #들어갈 수 있는 개수를 저장할 DP배열 설정
    dp = [1] * many

    #배열을 돌면서 그 상자가 마지막일 때 넣을 수 있는 상자의 최대 개수 구하기(DP사용)
    for i in range(many) :
        for j in range(i) :
            #박스가 더 작으면 넣을 수 있음
            if box[j] < box[i] :
                #최대로 넣을 수 있는 값은 현재 값 vs 이전 상자 +1 값과 비교해 더 큰 수 넣음
                dp[i] = max(dp[i], dp[j]+1)
    
    return(max(dp))


def main() :
    #상자의 개수 및 크기 입력
    many = int(input())
    box = list(map(int, input().split()))

    print(how(many, box))

if __name__ == '__main__' :
    main()



