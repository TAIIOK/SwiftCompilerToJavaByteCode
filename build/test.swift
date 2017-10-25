
var iop = 1

var a:[Int] = [2,1,3,7,5,8,4,6,9,10,11]

var i = 0

var size = a.count()

print("Input array elements")

while( i < size){
    var bs = readLine()
    a[i] = toInt(bs)
    i = i + 1

}




var temp = 0; // временная переменная для обмена элементов местами

var size = a.count()

var j = 0

for i in 0 ... size - 1 {

    for j in 0 ... size - i - 1{

        if (a[j] > a[j + 1]) {
            // меняем элементы местами
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }

}

i = 0

while( i < size){
    print(a[i])
    i = i + 1
}



print("Input first float element")

var first = readLine()

var flo:Float = toFloat(first)

print(flo)

print("Input second float element")

var second = readLine()

var flo1:Float = toFloat(second)

print(flo1)

print("DIV")

print(flo / flo1)

print("MUL")

print(flo * flo1)

print("SUM")

print(flo + flo1)

print("SUB")

print(flo - flo1)

var Example:String = "Privet"

var Example2:String = " kak dela"

print(Example + Example2)


func fac(num:Int,nul:Int) -> Int {
    if (num > 1){
        return 1
    }
    else{
        return 1
    }

    var iads = 0
    return iads
}





