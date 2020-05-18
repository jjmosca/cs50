select people.name from ((stars
inner join people on stars.person_id = people.id)
inner join movies on stars.movie_id = movies.id) where movies.title = 'Toy Story';