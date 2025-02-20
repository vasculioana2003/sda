Subiectul Ii. Fie un graf orientat G=INE) avand n noduri siarcele marate cu ponderi ne-negative w
descrise in matricea W. Explicati algoritmii de mai jos si identificati problemma pe grafuri pe care icestia o rezoiv. Calculati complexitatea acestor algoritmi si prezentati o modalitate de
imbunatatire a executiei acestora.

ALGORITHM1(L, W):
    n = L.rows
    fie L' = (l'ij)
    for i = 1 to n
        for j = 1 to n
            l'ij = ∞
            for k = 1 to n
                l'ij = min(l'ij, lij + wjk)
    return L'

ALGORITHM2(W):
    n = W.rows
    fie L(1) = W
    for m = 2 to n - 1
        L(m) = ALGORITHM1(L(m-1), W)
    return L(n-1)