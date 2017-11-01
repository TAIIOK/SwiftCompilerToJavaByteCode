func increment(digit: Int) -> Int {
    let ret =  digit + 1;
    print(ret)
    return ret
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




