z=input()
A={'c=':-1,'c-':-1,'dz=':-1,'d-':-1,'lj':-1,'nj':-1,'s=':-1,'z=':-1}
cnt=len(z)
for i in A.keys():
    cnt+=z.count(i)*A[i]
print(cnt)