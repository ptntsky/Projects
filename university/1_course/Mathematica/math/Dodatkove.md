Manipulate[
Column[{
Tooltip[
Graphics[{LightGray,Disk[{0,0},1],Black,Circle[{0,0},1],Thick,Blue,Arrow[{{0,0},{Cos[a],Sin[a]}}]},PlotRange->1.5,Axes->True,ImageSize->350],
"Це інтерактивний радіус-вектор.\nЙого кут змінюється за допомогою повзунка."
],
Row[{Button["Кут \[Pi]/2 (90°)",a=\[Pi]/2],Button["Кут \[Pi] (180°)",a=\[Pi]],Button["Скинути на 0",a=0]},Spacer[10]]
},Alignment->Center],
{{a,\[Pi]/4,"Кут повороту"},0,2 \[Pi],Appearance->"Labeled"}
]
