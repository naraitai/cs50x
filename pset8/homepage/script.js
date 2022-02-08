/*---------------------------------
Task 2 of 2

Brief
- Build a simple homepage with HTML, CSS and JavaScript
- Website must contain
    - A minimum of 4 different HTML pages
    - A minimum of 10 distinct HTML tags (other than <html>, <head>, <body> and <title>)
    - A minimum of 1 stylesheet
    - Use at least 5 different CSS selectors
    - Use at least 5 different CSS properties
    - A minimum of one Bootstrap feature
    - A minimum of one JavaScript feature that makes site more interactive
- Website must be able to
    - Navigate from any page to any page
    - Look good on both PC and mobile devices
    
Distribution code
- None

Key concept:
- Basic HTML, CSS and JavaScript
-----------------------------------*/

function visible() {
    document.getElementById('study').removeAttribute('hidden');
}

function reset() {
    document.getElementById('study').setAttribute('hidden', true);
}

