use foot;

delete from dispute;
delete from equipes;
delete from logo;
delete from matchs;

insert into equipes (idequipe,nomEquipe,region)
values (1,'PSG','France'),
       (2,'OL','France'),
       (3,'OM','France'),
       (4,'Manchester','Angleterre'),
       (5,'Chelsea','Angleterre'),
       (6,'Liverpool','Angleterre'),
       (7,'Bayern Munich','Allemagne'),
       (8,'Real Madrid','Espagne'),
       (9,'Juventus','Italie'),
       (10,'Calgari','Italie');



insert into matchs 
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
values (1,3,1),
       (1,5,3),
       (2,4,1),
       (2,6,1),
       (3,1,2),
       (3,7,0),
       (4,10,2),
       (4,2,2),
       (5,8,1),
       (5,9,0),
       (6,8,0),
       (6,2,3),
       (7,7,0),
       (7,1,1),
       (8,5,1),
       (8,6,2),
       (9,10,0),
       (9,4,2),
       (10,3,1),
       (10,9,3);