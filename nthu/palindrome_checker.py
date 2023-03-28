T = int(input())
for kase in range(1, T+1):
	li = list(map(int, input().split()))
	def chaewon(palin)->bool:
		for i in range(len(palin)//2):
			if palin[i] != palin[len(palin)-1-i]:
				return False
		return True
	if chaewon(li):
		print(f'Case #{kase}: Yes')
	else:
		print(f'Case #{kase}: No')
