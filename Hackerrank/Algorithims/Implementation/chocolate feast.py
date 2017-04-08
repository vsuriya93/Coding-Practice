# Enter your code here. Read input from STDIN. Print output to STDOUT
T = int(raw_input())
for i in range (0,T):
    A,B,C1 = [int(x) for x in raw_input().split(' ')]
    numberOfChocolates=A//B
    numberOfWrappers=numberOfChocolates
    numberOfWrappersRemaining=numberOfWrappers
    answer=numberOfChocolates
    while numberOfWrappersRemaining>=C1:
        extra=numberOfWrappersRemaining//C1
        answer+=extra
        numberOfWrappersRemaining-=(extra*C1)-extra
    print answer