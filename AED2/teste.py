m, n = input().split(" ")
m=int(m)
n=int(n)
s=0

print('\n')

if m>0 and n>0:
    while m>0 and n>0:
        if m>n:
            maior=m
            menor=n
        else:
            maior=n
            menor=m

        for i in range (menor,maior+1):
            print(i)
            s+=i
        print('Sum:', s,'\n')


        m, n = input().split(" ")
        m=int(m)
        n=int(n)