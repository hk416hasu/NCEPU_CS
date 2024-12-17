function fetchdata(callback) {
  setTimeout(() => {
    const data = 'Some data';
//    callback(data);
    console.log(callback + 1);
  }, 1000);
}

//fetchdata((data) => {
//  console.log(data);
//});

// fetchdata(100);

fetchdata((data) => {
  console.error(data);
});

// the callback will be defined when fetchdata call it,
// amazing!
