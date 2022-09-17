import turtle

w = turtle.Screen()
w.bgcolor("Black")

p1 = turtle.Turtle()
p2 = turtle.Turtle()

p1.color("yellow")
p1.setpos(0,0)
p1.speed(0)

p2.color("Blue")
p2.setpos(0,200)
p2.speed(0)

while True:
	p1.forward(390)
	p1.left(179)
	p2.forward(390)
	p2.right(89)

p1.exitonclick()
p2.exitonclick()