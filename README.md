# Church of the Damned 
C++ console game featuring exploration, combat, and inventory management in a church overtaken by evil.

### Game Storyline
You, the player, must defeat the forces of evil that have invaded your village's church. Monsters such as dark priets wielding deadly spells and undead choir boys with screeching, demonic voices stand in your way. Find treasure and loot the bodies of fallen enemies to find more powerful weapons and armor. Use special attacks and defense actions to supplement your standard attacks. Only then will you and your village survive the demonic power in the CHURCH OF THE DAMNED.

### C++ Features Used
- Inheritance and polymorphism for player's class and various classes of enemies 
- Smart pointers (particularly unique_ptr) for managing the player, enemies, treasure items, and rooms in the church
- 2D raw arrays for displaying rooms in the church 
- Input validation for player actions, such as moving around the church, attacking enemies, and picking up treasure 

### Design and Implementation Challenges 
- Migrating from raw pointers to smart pointers for treasure object management: move() function necessary to move ownership of object from church room to player's inventory 
- Improved encapsulation of inventory object: all inventory management now done through player's functions, which in turn call inventory functions 
- Special actions class structure: decided to use enum to track type of action rather than polymorphism. This better followed the Liskov Substitution Principle, because different types of actions (e.g. attacks, defense, restoration) were not interchangeable and therefore should not be designed with inheritance/polymorphism.
