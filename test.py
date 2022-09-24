def array_mult(A, B):
    ai = len(A)
    aj = len(A[0])
    bi = len(B)
    bj = len(B[0])
    assert aj == bi

    res = []
    for i in range(ai):
        list = []
        for j in range(bj):
            pro = 0
            for k in range(bi):
                pro += A[i][k] * B[k][j]
            list.append(pro)
        res.append(list)

    return res
print(array_mult([[1, 2, 3], [-2, 3, 7]], [[1], [0], [-1]]))