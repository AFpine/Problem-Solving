ans = 0
a = list(map(int, input().split()))
for i in range(5) :
    ans += a[i]*a[i]
print(ans % 10)