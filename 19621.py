
def meet(conver, n) :
    dp = [0] * (n+1)

    #회의가 하나만 들어올 경우의 예외처리
    if (n == 1) :
        return conver[0][2]

    #base case
    dp[1] = conver[0][2]
    dp[2] = max(dp[1], conver[1][2])


    #점화식, k번째 회의를 포함시킬 것인가 말 것인가를 결정함
    #k번째 회의가 k-1, k+1회의와 시간이 겹치므로 포함시키는 경우엔 i-2번째 + 현재 인원, 포함시키지 않는 경우엔 i-1번째 명수를 그대로 들고 옴 
    for i in range (3, n+1) :
        dp[i] = max(dp[i-2] + conver[i-1][2], dp[i-1])
    
    return max(dp)




def main() :
    #회의 시작, 종료, 참여 인원 입력 받음
    n = int(input())
    conver = []

    for i in range (0, n) :
        start, end, people = map(int, input().split())
        conver.append((start, end, people))

    print(meet(conver, n))
    

if __name__ == "__main__" :
    main()