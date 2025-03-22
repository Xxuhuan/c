import turtle
import time

def draw_pole():
    t.pensize(5)
    t.speed(0)
    for i in range(3):
        t.penup()
        t.goto(-200 + 200*i, -150)
        t.pendown()
        t.goto(-200 + 200*i, 150)

def create_disks(n):
    disks = []
    for i in range(n):
        disk = turtle.Turtle()
        disk.shape("square")
        disk.shapesize(1, (n-i)*1.5)
        disk.color("blue")
        disk.penup()
        disk.goto(-400, -130 + 20*i)
        disks.append(disk)
    return disks

def move_disk(start, end):
    disk = poles[start][-1]
    x = -200 + 200*end
    y = -130 + 20*(len(poles[end]))
    
    t.speed(1)
    disk.goto(-200 + 200*start, 160)
    disk.goto(x, 160)
    disk.goto(x, y)
    poles[end].append(poles[start].pop())

def hanoi(n, start, via, end):
    if n == 1:
        move_disk(start, end)
        return
    hanoi(n-1, start, end, via)
    move_disk(start, end)
    hanoi(n-1, via, start, end)

t = turtle.Turtle()
screen = turtle.Screen()
screen.tracer(0, 0)
t.hideturtle()

n = 4
poles = [[], [], []]

draw_pole()
poles[0] = create_disks(n)[::-1]
screen.update()

hanoi(n, 0, 1, 2)
turtle.done()
