# Computer Graphics Texturing Using OpenGL and C++

# Requirements
* Create a cube using glBegin()/glEnd() with triangles.
* Use the attached image (Sprite_Dice.bmp) to texture each face to create a dice.
* Please note that you need to texture the dice so that it appears the same as a real dice, with opposing faces adding up to 7.
* Animate the dice so that each face changes colour once a second

# How I implemented the tasks
For the first requirement, using inspiration from the previous assignment which I worked on, I created a cube using glBegin()/glEnd() with triangles. With this, I had completed the first requirement. Next, after getting the image from moodle, I divided 1 by 6 to get an estimate into the proportions of each face of the dice. Afterwards, I was able to get the correct points for each face and by using the vertices used to draw the cube, I started working from the bottom of the image and worked my way up. This is so that I could get a clear idea working my way from zero up.

After getting the coordinates for the faces, I used the classes from the labs which I completed in loading the bitmap into the code. At this point, I already knew how I will proceed so I drew my first level of the dice which was the colour cyan.
In order to fulfil the third request, I drew a plane of a dice and made sure to check each opposing faces adds up to 7. By using this plane, I adjusted all the drawn faces

Using the same points I used for the cyan, I just had to increase the “t” in glTexCoord2f to be able to move up the colours and render the dice. To achieve this, I transformed the cyan cube method into a “generic” cube method that takes in a colour parameter and adds it to the y to “move up” to the next colour. Additionally, I have added a “colours” array which contains the y (or “t” in glTexCoord2f) offset for each of the colours.
GlfwGetTime was helpful with achieving the fourth requirement. With the colours array in place, each colour was mapped to the relevant entry (0 – 5) which contains its offset, therefore using glfwGetTime I can floor the current second, and get one of the 6 colours, then use that to get its offset from the array, drawing the appropriately coloured cube. When glfwGetTime reaches 6, it gets reset to 0 to keep the “loop” going. This allowed me to fulfil the final requirement of this assignment as now the dice changes colours every second.
#
![image](https://user-images.githubusercontent.com/58789172/123663913-c202f100-d82e-11eb-9371-e2d6fff436d8.png)
# 
![image](https://user-images.githubusercontent.com/58789172/123663937-c6c7a500-d82e-11eb-963a-1fc239ba58c3.png)
