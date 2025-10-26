# FOCP-Assignment-1-Drone-Delivery-Simulator
# FOCP-Assignment-1-Drone-Delivery-Simulator
**Delivery Drone Simulator**

**1.	Title and Team Information**

   
**Project Title:** Delivery Drone Simulator 


**Team Members & Roles:**

 - ***Umayrah Masood Malik:*** Making a logical flowchart on which the code works and making a comprehensive readme.md on the GitHub        
   repository.

     

 - ***Bilal Ghazi:***  Implementing the logic of the flowchart and writing non-modularized version of the code which would later be     
   modified further. Will also be making the word document for the group
   assignment. Tested the code aswell.

    

 - ***Jyotish Kumar:*** Modularizing the code and optimizing for better execution of the program, as well as using good      
   programming practices and adding comments for better understanding.

**2.	Overview**


   This program simulates a drone delivery system that performs multiple delivery runs while reacting dynamically to environmental conditions such as weather, obstacles, and battery usage. It models real world drone logistics challenges like:


 - Delays due to rain;
 - Route rerouting due to obstacles;
 - Battery management and return-to-base logic;
 - Randomized system malfunctions.

The simulator provides a visualized, step-by-step sequence of delivery outcomes and evaluates performance using a rating system based on successful, failed, and delayed deliveries.


**3.	Program Design / Logic**


 The functions Implemented are as follows:
 
  

- display_performance(...): Displays delivery summary and performance metrics.
 
- get_starCount(int score): Calculates a performance rating (1–5 stars) based on final score.

- loading(int repetitions, int wait): Creates a visual delay using dots to simulate real-time waiting.

- obstacleExists(): Randomly decides whether or not an obstacle is there (1 in 3 chance). Returns a bool.

- random (int range, int base): Generates a random integer within the specified range.

- start_day(): Starts the deliveries.

- show_battery(int battery): Shows current drone battery percentage.


  

**4.	Logic Flow**

   
The user will start the simulation by pressing Enter.

For each delivery: Random conditions will be generated, for example:

•	Weather (Sunny/Windy/Rainy), Obstacle presence, Battery usage, Malfunction chance.

•	Then drone either:

 

 - Delivers successfully,

   
 

 - Is delayed (rain),

   
  

 - Reroutes (obstacle),

  

 - Fails due to malfunction,

   
 

 - Or returns to base if the battery is too low (and windy).
 

The system tracks:

	Number of successful, delayed, and failed deliveries,
  
	Remaining battery,
  
	Final score → converted to a star based rating.
  
Performance summary is displayed at the end.


   


**5.	Environmental Simulation**
   
Weather conditions influence whether deliveries proceed or are delayed.
Obstacles trigger rerouting logic and consume extra battery.
Randomness (using rand()) ensures variability in each simulation run.

**6.	Execution Instructions**

Compilation
   
Run
   
**Usage:**
   
Press ENTER to start.

The simulator will automatically perform 3 deliveries.

Wait for the summary and performance rating to appear.

Sample Output (Simplified):

Press ENTER to start deliveries

Delivery #1, Headed towards: H-12

............

DELIVERY SUCCESSFUL!

Battery Remaining: 75%

Delivery #2, FLIGHT DELAYED because of rain

Delivery #3, OBSTACLE DETECTED.....rerouting......

DELIVERY SUCCESSFUL!

Battery Remaining: 60%


Performance Rating: * * * *

Details:

(1) Total: [3]

(2) Successful: [2]

(3) Failed: [0]

(4) Delayed: [1]

(5) Battery left: [60%]




**7. Team Collaboration Summary:**
   
Each team member contributed to different aspects of the project as follows:

*Umayrah:* Making flowchart and maintain readme.md.

*Bilal:* Writing version#1 of the code and making the document.

*Jyotish:* Modularizing the code and adding finishing touches.


**8. Version Control**

   
All members committed to a shared GitHub repository using branch-based development.

Each member made at least one commit showing active participation.

**9. AI Tool Reflection**
    
Tools Used: ChatGPT (GPT-5)

**Usage Summary:**

Improving code readability.

Assisted in structuring the README.md file and refining project documentation.

**Learning Reflection:**

Using AI tools helped streamline the documentation process and encouraged more readable code.

However, the main logic and implementation decisions were developed independently by the team.


**10. Future Improvements**

- Drones could be made a class, with next location, battery, etc., as its properties. Further, they could be more interactive (user controlled).
- The drone could be made to work through the rain if the distance is short, however it will affect the battery strongly. Or other similar situations where the drone can try to avoid the obstacle, crash into it and either break (unable to do any more deliveries until repaired) or push through it with a heavily drained battery.
- More weather conditions could be introduced, like “Very Sunny” which increases battery drain (because of heat).
- Windy could make the speed of the drone decrease (time taken to reach increases).
- The code could be made more modular through functions like send_for_delivery(),  avoid_obstacle(), etc.



  
