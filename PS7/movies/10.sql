select distinct(people.name) from ((directors
inner join people on directors.person_id = people.id)
inner join ratings on directors.movie_id = ratings.movie_id) where ratings.rating >= 9;