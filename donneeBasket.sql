use basket;
---------------------------------------------------------------
-- supprime toutes les données dans la table ! important de le mettre dans le bonne ordre toujours de la dernière crée a la premièr
---------------------------------------------------------------
delete from dispute;
delete from equipes;
delete from logo;
delete from matchs;

---------------------------------------------------------------
-- insert des valeurs dans les attributs de la table 
---------------------------------------------------------------
insert into equipes (idequipe,nomEquipe,region)
values (1,'Lakers','Los Angeles'),
       (2,'Warrior','Golden State'),
       (3,'Celtics','Boston'),
       (4,'Nets','Brooklyn'),
       (5,'Bucks','Milwaukee'),
       (6,'Raptors','Toronto'),
       (7,'Bulls','Chicago'),
       (8,'Knicks','New York'),
       (9,'Clippers','Los Angeles'),
       (10,'Suns','Phoenix');



insert into matchs -- si tu n'indiques pas d'attributs tu dois remplirs toutes les variables dans l'ordre
values (1,'2020-07-05'),
       (2,'2020-07-05'),
       (3,'2020-07-05'),
       (4,'2020-07-05'),
       (5,'2020-07-05'),
       (6,'2020-07-12'),
       (7,'2020-07-12'),
       (8,'2020-07-12'),
       (9,'2020-07-12'),
       (10,'2020-07-12');


insert into dispute 
values (1,3,14,21,15,25),
       (1,4,23,14,24,11),
       (2,7,25,23,17,19),
       (2,1,14,24,10,10),
       (3,9,23,24,25,21),
       (3,5,23,13,16,10),
       (4,8,13,24,20,19),
       (4,6,10,21,22,15),
       (5,2,15,25,10,19),
       (5,10,20,13,19,23),
       (6,1,21,22,20,17),
       (6,5,23,20,17,14),
       (7,10,22,18,16,13),
       (7,3,10,16,22,19),
       (8,8,21,22,10,22),
       (8,4,19,14,11,20),
       (9,6,15,25,20,14),
       (9,9,14,17,24,13),
       (10,7,20,16,19,25),
       (10,2,10,24,17,11);