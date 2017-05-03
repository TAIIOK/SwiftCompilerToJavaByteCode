//  Test.swift
//  Created by Roman Efimov on 22.02.17.
//  Copyright © 2017 Roman Efimov. All rights reserved.
//
/*
 
 {"StickerPacks":[
 {
 "name": "test",
 "count": 1,
 "links": ["https://pp.vk.me/c606621/v606621505/7af7/dZnzJQLMFVs.jpg"]
 }
 ]
 }
 */
import Foundation

1
-1

var line = readLine()
print(line)

var varuble = 4
let constant = 3
var double = 3123.1231231
var hex = 0xFFF                 // 4095 in hexadecimal notation
let binaryInteger = 0b10001     // 17 in binary notation
let octalInteger = 0o21			// 17 in octal notation
var trueBool:Bool = true
var falseBool:Bool = false
var int:Int = 0
var char:Character = "s"
var string:String = "string"
var doublevar:Double = 0.1
var float:Float = 0.1

var stressline = "new line \n \\ !@#$%^&*() \"\" \" ' ' ' ' ' ' ' " + " \\\\ \n\r\t 1234567890 "  + line! + "\(hex)"

var SD = "SD"

var __ = SD
__ = "s"

var $ = 5

var massive:[Int] = []
var someInts = [Int]()

print("array size\(someInts.count)")

var stringvar = "testing string"

print("string size\(stringvar.characters.count)")

if (!trueBool || falseBool ){
}

if (trueBool || falseBool ){
}

if (trueBool && falseBool ){
}

if varuble == constant {
    print("равны\(1 + 2)")
}
else if (varuble < constant){
}
else {
}

while varuble != constant{
}

repeat{
    print("\(int)")
    int = int + 1
}while (varuble>constant)

for index in 1...5 {
    print("\(index) times 5 is \(index * 5)")
}

func myFuncOneParam(dad:Int) -> Bool {
    return true
}
func myFuncMoreThanOneParam(dad:Int,str:String,bo:Bool) -> Bool {
    return true
}

var resultone = myFuncOneParam(dad: 1)
var resultsecond = myFuncMoreThanOneParam(dad: 1, str: "", bo: true)

switch trueBool {
case true:
    break
case false: break
default: break
}
