
#include "Movie_Validator.h"





ValidationException::ValidationException(std::string _message) : message{ _message }
{
}

std::string ValidationException::getMessage() const
{
	return this->message;
}




void MovieValidator::validate(const Movie & m)
{
	std::string errors;


	if (m.getTitle().size() <= 0)
		errors += std::string("The movie title cannot be empty!\n");
	if (m.getGenre().size() <= 0)
		errors += std::string("The movies genre cannot be empty!\n");
	if (m.getYear() < 1890)
		errors += std::string("Your movie cannot possibly be that old!\n");
	if (m.getLikes() <= 0)
		errors += std::string("Number of likes must be a positive number!\n");

	if (errors.size() > 0)
		throw ValidationException(errors);


}

