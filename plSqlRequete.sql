------------------------------------------------------------------------------------
-- 13/09/2021
------------------------------------------------------------------------------------

do $$
<<first_block>>
declare
	prenom varchar:='';
begin
	-- get the name of Mr chase
	select first_name
	into prenom
	from actor
	where last_name = 'Chase';
	-- display a message 
	raise notice  '%', prenom;
end first_block $$;

------------------------------------------------------------------------------------
-- 13/09/2021
------------------------------------------------------------------------------------

do $$
<<first_block>>
declare
	selected_actor actor%rowtype;
begin
	-- select actor with id 10
	select *
	from actor
	into selected_actor
	where actor_id = 10;
	
	-- show the name of actor 
	raise notice 'the actor name is % %',
		selected_actor.first_name,
		selected_actor.last_name
end $$;

------------------------------------------------------------------------------------
-- 13/09/2021
------------------------------------------------------------------------------------

do $$
<<first_block>>
declare
	description_film varchar :='';
begin
	-- select the name of the film with id 129
	select description
	from film
	into description_film
	where film_id = 129;
	
	-- show the description of the film 
	raise notice 'description : %',
		description_film;
end $$;

------------------------------------------------------------------------------------
-- 13/09/2021
------------------------------------------------------------------------------------

do $$
<<first_block>>
declare
	genre varchar :='';
begin
	-- select the category of first film
	select category.name
	from category
	inner join film_category on category.category_id = film_category.category_id
	inner join film on film_category.film_id = film.film_id
	into genre
	where film.film_id = 1;
	
	-- show the name's category
	raise notice 'genre : %',
		genre;
end $$;

------------------------------------------------------------------------------------
-- 13/09/2021
------------------------------------------------------------------------------------

do $$
<<first_block>>
declare
	existence varchar :='';
begin
	-- select the tilte's film
	select film_id
	from film
	into existence
	where film_id = 1;
	if existence is null then existence = 'non';
	else existence = 'oui';
	end if;
	
	-- show if the film exist 
	raise notice 'il existe : %',
		existence;
end $$;

------------------------------------------------------------------------------------
-- 13/09/2021
------------------------------------------------------------------------------------

do $$
<<first_block>>
declare
             nombre_film int:=0;
			 compteur int:=0;
			 chocolat varchar:='';
			 titre varchar:='';
begin    

	-- definir le nbr max de film 
	select count(title)
	from film
	into nombre_film;

	-- boucle pour afficher tout les science fiction
	while compteur <= nombre_film loop

		-- selectionner tout les films de science fiction
		select title
		from film
		left join film_category on film_category.film_id = film.film_id
		left join category on film_category.category_id = category.category_id 
		into chocolat
		where  category.name = 'Sci-Fi'
		group by film.film_id
		having film.film_id = compteur
		order by title;

		-- affiche le nom du film si c'est un film de science fiction
		if chocolat is not null then
		raise notice 'film : % ', chocolat;
		end if;
	compteur=compteur + 1;
	end loop;
end $$;
	
------------------------------------------------------------------------------------
-- 14/09/2021
------------------------------------------------------------------------------------

do $$
<<first_block>>
declare
	duree int :='0';
begin    

	-- selectionne la durée du film qui pour id 506
	select film.length 
	from film
	into duree
	where film_id = 506;
	
	-- description du film en fonction de sa duree
	if duree is null then
		raise notice 'ce film n existe pas';
	
	elseif duree <= 50 then 
		raise notice 'ce film est court : % min', duree;
	
	elseif duree > 50 and duree < 120 then 
		raise notice 'ce film a une durée moyenne : % min', duree;
	
	else 
		raise notice 'ce film est long : % min', duree;
		
	end if;
	
end $$;

------------------------------------------------------------------------------------
-- 14/09/2021
------------------------------------------------------------------------------------

do $$
<<first_block>>
declare
	duree int :=0;
begin    

	-- selectionne la durée du film qui pour id 506
	select film.length
	from film
	into duree
	where film_id = 506;

	-- description du film en fonction de sa duree
	case 
		when duree is null then 
			raise notice 'film introuvable';
	
		when duree <= 50 then 
			raise notice 'duree film courte : % min', duree;
	
		when duree < 120 then 
			raise notice 'duree film moyenne : % min', duree;
	
		else 
			raise notice 'duree film longue : % min', duree;
	end case;
end $$;

------------------------------------------------------------------------------------
-- 15/09/2021
------------------------------------------------------------------------------------

--------------------------
-- création de la fonction
-------------------------- 
create or replace function get_film_lenght(len_from int, len_to int)
returns int
language plpgsql

as
$$
declare 
	nombre int:=0;
begin 
	select count(*)
	from film
	into nombre
	where film.length >= len_from and film.length <= len_to;
	
	return nombre;
	
end$$;

-----------------------
-- appel de la fonction
-----------------------

do
$$
<<first_block>>

declare

	nombre_film int:=0;
	
begin 

	nombre_film := get_film_lenght(10,60);
	
	raise notice 'nombre de film : %', nombre_film;
	
end $$;

------------------------------------------------------------------------------------
-- 15/09/2021
------------------------------------------------------------------------------------

--------------------------
-- création de la fonction
-------------------------- 
create or replace function get_film_stat(
	 out min_len int,
	 out max_len int,
	 out avg_len numeric)
language plpgsql
as $$ 
begin

	select min(length),
		   max(length),
		   avg(length)::numeric(5,1)
	into min_len, max_len, avg_len
	from film;

end $$;

-----------------------
-- appel de la fonction
-----------------------

select *
from get_film_stat();

------------------------------------------------------------------------------------
-- 15/09/2021
------------------------------------------------------------------------------------

--------------------------
-- création de la fonction
-------------------------- 

create or replace function get_film(
	 inout min_len int,
	 inout max_len int,
	 inout avg_len numeric)
language plpgsql
as $$ 
begin

	select min(length),
		   max(length),
		   avg(length)::numeric(5,1)
	into min_len, max_len, avg_len
	from film;
	
end $$;

-----------------------
-- appel de la fonction
-----------------------

do $$

declare

	maxi int:=0;
	mini int:=0;
	average numeric;
	
begin

	select *
	from get_film_stat(5,15,35)
	into maxi, mini, average;

	raise notice '%,%,%', maxi, mini, average;
	
end $$;

------------------------------------------------------------------------------------
-- 15/09/2021
------------------------------------------------------------------------------------

--------------------------
-- création de la fonction
-------------------------- 

create or replace function get_rental_duration(in client int)
returns int
language plpgsql

as $$

declare
	duree int:=0;
begin

	select  sum(extract(day from return_date - rental_date))
	from rental
	where customer_id = client
	into duree;
	
	return duree;
	
end$$;

-----------------------
-- appel de la fonction
-----------------------

do $$

declare 
	total int:=0;
	
begin 

	total = get_rental_duration(20);
	
	raise notice '%', total;
	
end $$;

------------------------------------------------------------------------------------
-- 15/09/2021
------------------------------------------------------------------------------------

--------------------------
-- création de la fonction
-------------------------- 

create or replace function get_rental_duration(in client int, in date_precise date)
returns int
language plpgsql

as $$

declare
	duree int:=0;
begin

	select  sum(extract(day from return_date - rental_date))
	from rental
	where customer_id = client and rental_date >= date_precise
	into duree;
	
	return duree;
	
end$$;

-----------------------
-- appel de la fonction
-----------------------

do $$

declare 
	total int:=0;
	
begin 

	total = get_rental_duration(20, '2005-06-24');
	
	raise notice '%', total;
	
end $$;

------------------------------------------------------------------------------------
-- 15/09/2021
------------------------------------------------------------------------------------

--------------------------
-- création de la fonction
-------------------------- 

create or replace function get_rental_duration(in client int, in date_precise date)
returns int
language plpgsql

as $$

declare
	duree int:=0;
begin

	select  sum(extract(day from return_date - rental_date))
	from rental
	where customer_id = client and rental_date >= date_precise
	into duree;
	
	return duree;
	
end$$;

-----------------------
-- appel de la fonction
-----------------------

do $$

declare 
	total int:=0;
	
begin 

	total = get_rental_duration(20, '2005-08-02');
	
	raise notice '%', total;
	
end $$;

------------------------------------------------------------------------------------
-- 15/09/2021 "exception"
------------------------------------------------------------------------------------

do $$
declare

	selected_film film%rowtype;
	input_film_id film.film_id%type :=1;

begin

    select film_id, title
	from film 
	into strict selected_film
    where film_id = input_film_id ;
	
	raise notice 'the film title is %', selected_film.title;

EXCEPTION 

   WHEN no_data_found THEN 
      raise notice 'film not found';
	  
end $$;

------------------------------------------------------------------------------------
-- 15/09/2021 "exception multiples"
------------------------------------------------------------------------------------

do $$
declare

	selected_film film%rowtype;
	input_film_id film.film_id%type :=1;

begin

    select  film.length, title
	from film 
	into strict selected_film
    where film.length = 0;
	
	raise notice 'the film title is %', selected_film.title;

EXCEPTION 

	WHEN no_data_found THEN 
		raise notice 'film not found';

	when too_many_rows then 
		raise notice 'trop de lignes';
	  
end $$;

------------------------------------------------------------------------------------
-- 15/09/2021 "exception multiples"
------------------------------------------------------------------------------------

do $$ 

declare 
	
	genre varchar :='';
	
begin 
	
	select category.name
	from category
	inner join film_category on category.category_id = film_category.category_id
	inner join film on film_category.film_id = film.film_id
	into strict genre
	where film.film_id = 0;
	
	raise notice 'category : %', genre;
	
exception 
	
		WHEN no_data_found THEN 
		raise notice 'film not found';
		
end $$;