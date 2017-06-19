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

var SD = "SD"

var __ = SD
__ = "s"

var $ = 5

var massive:[Int] = []


print("array size\(someInts.count)")

var stringvar = "testing string"

//print("string size\(stringvar.characters.count)")

if (!trueBool || falseBool ){
}

if (trueBool || falseBool ){
}

if (trueBool && falseBool ){
}

if varuble == constant {
    print("равны\(2)")
}
else if (varuble < constant){
}
else {
}

while varuble != constant{
}

repeat{
    print("\(int)")
    int = int + 22
}while (varuble>constant)

for index in 3...6 {
    print("\(index) times 5 is \(index)")
}



func myFunc(){
    
    var bar = 90
    
}

var  sdb = "ss"


func myssFuncs(){
    
    var bar = 91
    
}
switch trueBool {
case true:
    break
case false: break
default: break
}
