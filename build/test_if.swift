var a = 1
var b = 4
if a < b {
	a+=1;
}
print(a)

if b > a{
	b=a+b
}
else{
	 b=b-1
}
print(b)

if a==b{
	print("wow")
}
else if a < b{
	print("cool!")
}
else{
	print("how?")
}

if(a < b){
	if( b > 3 ){
		print("B printed")
	}
	else{
		print("A printed")
	}
}
