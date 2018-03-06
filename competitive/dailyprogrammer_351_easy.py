	def convert_hex(num):
		alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
		res = ""
		if num == 0:
			return "0"
		while(num>=1):
			r = num%62
			num = num//62
			res = res + alphabet[r]
		return res

 	