def det(xr, xc, M):
    assert xr == xc
    r, c = xr, xc
    m = [[M[i][j] for j in range(c)] for i in range(r)]
    ans = 1
    for col in range(c):
        v = [math.fabs(row[col]) for row in m[col:]]
        pivot = max(v)
        if pivot == 0:
            return 0
        pivot_index = v.index(pivot)+col
        pivot = m[pivot_index][col]
        pivot_row = [x / pivot for x in m[pivot_index]]
        ans = ans*pivot
        if pivot_index != col:
            temp = m[col]
            m[col] = pivot_row
            m[pivot_index] = temp
            ans *= -1   #互换行列式两行，需要变号
        else:
            m[col] = pivot_row
        for i in range(col+1, r):
            k = m[i][col]
            m[i] = [m[i][j]-k*pivot_row[j] for j in range(c)]
    return ans
