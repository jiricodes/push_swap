class PushSwap:

	def __init__(self, stack_a):
		self.a = stack_a.copy()
		self.b = list()
		self.cmd = list()
	
	def __str__(self):
		return f"A: {self.a}\nB: {self.b}\nCMD: {self.cmd}"

	def sa(self):
		if len(self.a) > 1:
			second = self.a.pop(1)
			self.a.insert(0, second)
		self.cmd.append("sa")

	def sb(self):
		if len(self.b) > 1:
			second = self.b.pop(1)
			self.b.insert(0, second)
		self.cmd.append("sb")

	def ss(self):
		self.sa()
		self.sb()
		self.cmd.pop()
		self.cmd.pop()
		self.cmd.append("ss")
	
	def pa(self):
		if len(self.b) > 0:
			self.a.insert(0, self.b.pop(0))
		self.cmd.append("pa")
	
	def pb(self):
		if len(self.a) > 0:
			self.b.insert(0, self.a.pop(0))
		self.cmd.append("pb")
	
	def ra(self):
		if len(self.a) > 1:
			first = self.a.pop(0)
			self.a.append(first)
		self.cmd.append("ra")

	def rb(self):
		if len(self.b) > 1:
			first = self.b.pop(0)
			self.b.append(first)
		self.cmd.append("rb")

	def rr(self):
		self.ra()
		self.rb()
		self.cmd.pop()
		self.cmd.pop()
		self.cmd.append("rr")

	def rra(self):
		if len(self.a) > 1:
			last = self.a.pop()
			self.a.insert(0, last)
		self.cmd.append("rra")

	def rrb(self):
		if len(self.b) > 1:
			last = self.b.pop()
			self.b.insert(0, last)
		self.cmd.append("rrb")

	def rrr(self):
		self.rra()
		self.rrb()
		self.cmd.pop()
		self.cmd.pop()
		self.cmd.append("rrr")
	
	def checker(self, cmd_lst):
		for cmd in cmd_lst:
			if cmd == "sa": self.sa()
			elif cmd == "sb": self.sb()
			elif cmd == "ss": self.ss()
			elif cmd == "pa": self.pa()
			elif cmd == "pb": self.pb()
			elif cmd == "ra": self.ra()
			elif cmd == "rb": self.rb()
			elif cmd == "rr": self.rr()
			elif cmd == "rra": self.rra()
			elif cmd == "rrb": self.rrb()
			elif cmd == "rrr": self.rrr()
			else:
				print(f"Wrong command - {cmd}")
				return False
		sorted_a = self.a[:]
		sorted_a.sort()
		if self.a == sorted_a and self.b == []:
			return True
		else:
			return False

def ps_checker(org_lst, cmd_lst):
	ps = PushSwap(org_lst)
	if ps.checker(cmd_lst):
		res = "OK" + ps.__str__()
	else:
		res = "KO" + ps.__str__()
	del ps
	return res