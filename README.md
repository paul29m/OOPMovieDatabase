# OOPMovieDatabase -> Watchlist(CSV or HTML)

2.LMDB–LOCAL MOVIE DATABASE

So many movies, so little time... To make sure you do not miss any good movies, you absolutely need a software application to help
you manage your films and create watchlists.
The application can be used in two modes: administrator and user. When the application is started, it will offer the option to choose the mode.

Administrator  mode:  
The  application  will  have  a database, which  holds  all  the movies. 
You  must  be able to update the database, meaning: add a new movie, delete a movieand update the information of a movie. Each 
Movie has a title, a genre, a yearof release, a number of likes and a trailer. The traileris memorised as a link towards an online
resource. The administrators will also have the option to see all the movies in the database.

User mode: A user can create a watch listwith the movies that he wants to watch. The application will allow the user to:

a.See  the moviesin  the  databasehaving  a  given  genre(if  the  genre  is  empty,  see  all  the movies),  one  by one.  When  
the  user  chooses  this  option,  the  data  of  the  first movie(title, genre, year of release, number of likes) is displayed and 
the trailer is played in the browser. 

b.If the user likes the trailer, he/she can choose to add the movie to his/her watch list.

c.If the trailer is not  satisfactory, the user  can choose not  to add the movie  to the watch listand to continue to the next. In 
this case, the information corresponding to the next movieis shown  and  the  user  is  again  offered  the  possibility  to add
it  to  the  watch  list.  This  can continue as long as the user wants, as when arriving to the end of the listof movies with the 
given genre, if the user chooses next, the application will AGAIN show the fisrt movie.

d.Delete  a  movie  from  the  watch  list,  after  the  user  watched  the  movie. Whendeleting a movie from the watch list,
the user can also rate the movie (with a like), and in this case, the likes of the movie in the repository will be increased.

e.See the watch list in a TEXTFILE or in a HTML file.
