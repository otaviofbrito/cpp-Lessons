  cout << "Do you want to remove this car(y/n)? ";
      cin >> ans;
      while (ans != "y" && ans != "n")
      {
        cout << "Enter valid values!" << endl;
        cin >> ans;
      }
      if (ans == "y")
      {
        removeCar(dcar, c, tam);
      }
      else
      {
      }


      cout << "Do you want to add this car(y/n)? ";
  cin >> ans;
  while (ans != "y" && ans != "n")
  {
    cout << "Enter valid values!" << endl;
    cin >> ans;
  }
  if (ans == "y")
  {
    insertCar(dcar, tam);
  }
  else
  {
    exit(0);
  }