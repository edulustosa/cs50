const input = document.querySelector("input");

input.addEventListener("keyup", function(e) {
  const name = document.querySelector("p");

  if (input.value) {
    name.innerHTML = `hello, ${input.value}`;
  } else {
    name.innerHTML = `hello, whoever you are`;
  }
});
