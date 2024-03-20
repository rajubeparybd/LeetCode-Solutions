SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;

-- SOLUTION 2
SELECT DISTINCT class
FROM Courses
WHERE (SELECT COUNT(*) FROM Courses As c WHERE c.class = Courses.class) >= 5