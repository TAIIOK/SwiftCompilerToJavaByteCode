func increment(digit: Int) -> Int {
    let result =  digit + 1;
	print(result)
    return result
}
var a = 3
var b = 0;
var c:Float = 3.443
b = increment(digit:a)
print(b)

func ifelse(digit: Int, digit2:Int ) -> Int {
    var result = 0
	if(a > b){
		result = digit + 1;
	}
	else{
		result = digit2 + 10
	}
	print(result)
    return result
}

print(a)
a = ifelse(digit:a, digit2:b)

func printf(digit: Float) {
	print(digit)
}
printf(digit:c)