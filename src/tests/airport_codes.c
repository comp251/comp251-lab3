// clang-format off
char *codes[] = {
    "ABI",  // Abilene, Texas
    "CAK",  // Akron/Canton, Ohio
    "ALB",  // Albany, New York
    "ABQ",  // Albuquerque, New Mexico
    "ABE",  // Allentown, Pennsylvania
    "AMA",  // Amarillo, Texas
    "ANC",  // Anchorage, Alaska
    "ATW",  // Appleton, Wisconsin
    "ATL",  // Atlanta, Georgia
    "AUS",  // Austin, Texas
    "BFL",  // Bakersfield, California
    "BWI",  // Baltimore, Maryland
    "BGR",  // Bangor, Maine
    "BTR",  // Baton Rouge, Louisiana
    "BPT",  // Beaumont/Port Arthur, Texas
    "BIL",  // Billings, Montana
    "BHM",  // Birmingham, Alabama
    "BMI",  // Bloomington, Illinois
    "BOI",  // Boise, Idaho
    "BOS",  // Boston, Massachusetts
    "BUF",  // Buffalo, New York
    "BUR",  // Burbank, California
    "BTV",  // Burlington, Vermont
    "YYC",  // Calgary, Canada
    "CID",  // Cedar Rapids, Iowa
    "CMI",  // Champaign/Urbana, Illinois
    "CHS",  // Charleston, South Carolina
    "CLT",  // Charlotte, North Carolina
    "CHA",  // Chattanooga, Tenessee
    "MDW",  // Chicago, Illinois (Midway)
    "ORD",  // Chicago, Illlinois (O'Hare)
    "CVG",  // Cincinnati, Ohio
    "CLE",  // Cleveland, Ohio
    "COS",  // Colorado Springs, Colorado
    "CAE",  // Columbia, South Carolina
    "CMH",  // Columbus, Ohio
    "CRP",  // Corpus Christi, Texas
    "DFW",  // Dallas/Fort Worth, Texas
    "DAY",  // Dayton, Ohio
    "DEN",  // Denver, Colorado
    "DSM",  // Des Moines, Iowa
    "DET",  // Detroit, Michigan (City)
    "DTW",  // Detroit, Michigan (Metro)
    "DBQ",  // Dubuque, Iowa
    "DRO",  // Durango, Colorado
    "ELP",  // El Paso, Texas
    "EUG",  // Eugene, Oregon
    "EVV",  // Evansville, Indiana
    "FAI",  // Fairbanks, Alaska
    "FYV",  // Fayetteville, Arkansas
    "FNT",  // Flint, Michigan
    "FLO",  // Florence, South Carolina
    "FAT",  // Fresno, California
    "FLL",  // Fort Lauderdale, Florida
    "RSW",  // Fort Myers, Florida
    "FSM",  // Fort Smith, Arkansas
    "VPS",  // Fort Walton Beach, Florida
    "FWA",  // Fort Wayne, Indiana
    "GRR",  // Grand Rapids, Michigan
    "GRB",  // Green Bay, Wisconsin
    "GSP",  // Greeneville/Spartanburg, South Carolina
    "GSO",  // Greensboro, North Carolina
    "GUC",  // Gunnison, Colorado
    "YHZ",  // Halifax, Canada
    "HRL",  // Harlingen, Texas
    "MDT",  // Harrisburg, Pennsylvania
    "BDL",  // Hartford, Connecticut
    "ITO",  // Hilo, Hawaii
    "HNL",  // Honolulu, Hawaii
    "HOU",  // Houston, Texas (Hobby)
    "IAH",  // Houston, Texas (Intercontinental)
    "HSV",  // Huntsville, Alabama
    "IND",  // Indianapolis, Indiana
    "ISP",  // Islip, New York
    "JAN",  // Jackson, Mississippi
    "JAC",  // Jackson Hole, Wyoming
    "JAX",  // Jacksonville, Florida
    "KOA",  // Kailua-Kona, Hawaii
    "AZO",  // Kalamazoo, Michigan
    "MCI",  // Kansas City, Missouri
    "EYW",  // Key West, Florida
    "TYS",  // Knoxville, Tennessee
    "LSE",  // La Crosse, Wisconsin
    "LFT",  // Lafayette, Louisiana
    "LCH",  // Lake Charles, Louisiana
    "LAN",  // Lansing, Michigan
    "LAS",  // Las Vegas, Nevada
    "LEX",  // Lexington, Kentucky
    "LIH",  // Lihue, Kauai, Hawaii
    "LNK",  // Lincoln, Nebraska
    "LIT",  // Little Rock, Arkansas
    "LGB",  // Long Beach, California
    "LAX",  // Los Angeles, California
    "SDF",  // Louisville, Kentucky
    "LBB",  // Lubbock, Texas
    "MSN",  // Madison, Wisconsin
    "MHT",  // Manchester, New Hampshire
    "MQT",  // Marquette, Michigan
    "OGG",  // Maui, Hawaii
    "MFE",  // McAllen, Texas
    "MFR",  // Medford, Oregon
    "MLB",  // Melbourne, Florida
    "MEM",  // Memphis, Tennessee
    "MIA",  // Miami, Florida
    "MKE",  // Milwaukee, Wisconsin
    "MSP",  // Minneapolis, Minnesota
    "MOB",  // Mobile, Alabama
    "MLI",  // Moline, Illinois
    "MKK",  // Molokai, Hawaii
    "MRY",  // Monterey, California
    "MGM",  // Montgomery, Alabama
    "YUL",  // Montréal, Canada
    "MKG",  // Muskegon, Michigan
    "MYR",  // Myrtle Beach, South Carolina
    "BNA",  // Nashville, Tennessee
    "HVN",  // New Haven, Connecticut
    "MSY",  // New Orleans, Louisiana
    "JFK",  // New York, New York (Kennedy)
    "LGA",  // New York, New York (La Guardia)
    "EWR",  // Newark, New Jersey
    "SWF",  // Newburgh/Stewart Field, New York
    "PHF",  // Newport News, Virginia
    "ORF",  // Norfolk, Virginia
    "OAK",  // Oakland, California
    "MAF",  // Odessa/Midland, Texas
    "OKC",  // Oklahoma City, Oklahoma
    "OMA",  // Omaha, Nebraska
    "ONT",  // Ontario, California
    "SNA",  // Orange County, California
    "MCO",  // Orlando, Florida
    "YOW",  // Ottawa, Canada
    "OWB",  // Owensboro, Kentucky
    "OXR",  // Oxnard, California
    "PSP",  // Palm Springs, California
    "PSC",  // Pasco, Washington
    "PNS",  // Pensacola, Florida
    "PIA",  // Peoria, Illinois
    "PHL",  // Philadelphia, Pennsylvania
    "PHX",  // Phoenix, Arizona
    "PIT",  // Pittsburgh, Pennsylvania
    "PWM",  // Portland, Maine
    "PDX",  // Portland, Oregon
    "PVD",  // Providence, Rhode Island
    "YQB",  // Quebec, Canada
    "RDU",  // Raleigh-Durham, North Carolina
    "RNO",  // Reno, Nevada
    "RIC",  // Richmond, Virginia
    "ROA",  // Roanoke, Virginia
    "RST",  // Rochester, Minnesota
    "ROC",  // Rochester, New York
    "SMF",  // Sacramento, California
    "SLC",  // Salt Lake City, Utah
    "SJT",  // San Angelo, Texas
    "SAT",  // San Antonio, Texas
    "SAN",  // San Diego, California
    "SFO",  // San Francisco, California
    "SJC",  // San Jose, California
    "SBA",  // Santa Barbara, California
    "SRQ",  // Sarasota, Florida
    "SAV",  // Savannah, Georgia
    "SEA",  // Seattle, Washington
    "SHV",  // Shreveport, Louisiana
    "FSD",  // Sioux Falls, South Dakota
    "SBN",  // South Bend, Indiana
    "GEG",  // Spokane, Washington
    "SPI",  // Springfield, Illinois
    "SGF",  // Springfield, Missouri
    "STL",  // St. Louis, Missouri
    "SYR",  // Syracuse, New York
    "TLH",  // Tallahassee, Florida
    "TPA",  // Tampa, Florida
    "TOL",  // Toledo, Ohio
    "YYZ",  // Toronto, Canada
    "TVC",  // Traverse City, Michigan
    "TRI",  // Tri City, Tennessee
    "TUS",  // Tucson, Arizona
    "TUL",  // Tulsa, Oklahoma
    "EGE",  // Vail, Colorado
    "YVR",  // Vancouver, Canada
    "ACT",  // Waco, Texas
    "IAD",  // Washington, D.C. (Dulles)
    "DCA",  // Washington, D.C. (National)
    "CWA",  // Wausau/Stevens Point, Wisconsin
    "PBI",  // West Palm Beach, Florida
    "HPN",  // Westchester County, New York
    "ICT",  // Wichita, Kansas
    "ILM",  // Wilmington, North Carolina
    "AVP",  // Wilkes Barre, Pennsylvania
    "AUH",  // Abu Dhabi, United Arab Emirates
    "ACA",  // Acapulco, Mexico
    "GUM",  // Agana, Guam
    "AMM",  // Amman, Jordan
    "AMS",  // Amsterdam, Netherlands
    "ASU",  // Asuncion, Paraguay
    "ATH",  // Athens, Greece
    "AKL",  // Auckland, New Zealand
    "BAH",  // Bahrain
    "BKK",  // Bangkok, Thailand
    "BCN",  // Barcelona, Spain
    "PEK",  // Beijing, China
    "BFS",  // Belfast, Northern Ireland, United Kingdom
    "BJY",  // Belgrade, Yugoslavia
    "BZE",  // Belize City, Belize
    "BER",  // Berlin, Germany
    "BIM",  // Bimini, Bahamas
    "BOG",  // Bogota, Columbia
    "BOM",  // Bombay, India
    "CGN",  // Bonn, Germany
    "BRU",  // Brussels, Belgium
    "OTP",  // Bucharest, Romania
    "BUD",  // Budapest, Hungary
    "EZE",  // Buenos Aires, Argentina
    "CUN",  // Cancun, Mexico
    "CPT",  // Cape Town, South Africa
    "CCS",  // Caracas, Venezuela
    "CMN",  // Casablanca, Morocco
    "CMB",  // Colombo, Sri Lanka
    "CZM",  // Cozumel, Mexico
    "DOM",  // Dominica
    "DUB",  // Dublin, Ireland
    "DUS",  // Dusseldorf, Germany
    "FRA",  // Frankfurt, Germany
    "GVA",  // Geneva, Switzerland
    "GLA",  // Glasgow, United Kingdom
    "GOT",  // Gothenburg, Sweden
    "GHB",  // Governors Harbour, Bahamas
    "GDL",  // Guadalajara, Mexico
    "GUA",  // Guatemala City, Guatemala
    "GYE",  // Guayaquil, Ecuador
    "HAM",  // Hamburg, Germany
    "HAN",  // Hanoi, Vietnam
    "HEL",  // Helsinki, Finland
    "HIW",  // Hiroshima, Japan
    "HKG",  // Hong Kong, China
    "HUX",  // Huatulco, Mexico
    "IST",  // Istanbul, Turkey
    "ZIH",  // Ixtapa, Mexico
    "CGK",  // Jakarta, Indonesia
    "JNB",  // Johannesburg, South Africa
    "KBP",  // Kiev, Ukraine
    "KIN",  // Kingston, Jamaica
    "BJX",  // Leon, Mexico
    "LIM",  // Lima, Peru
    "LIS",  // Lisbon, Portugal
    "LGW",  // London (Gatwick), United Kingdom
    "LHR",  // London (Heathrow), United Kingdom
    "SJD",  // Los Cabos, Mexico
    "LYN",  // Lyon, France
    "MAD",  // Madrid, Spain
    "MGA",  // Managua, Nicaragua
    "MAN",  // Manchester, England
    "MNL",  // Manila, Philippines
    "MZT",  // Mazatlan, Mexico
    "MEL",  // Melbourne, Australia
    "MEX",  // Mexico City, Mexico
    "MXP",  // Milan (Malpensa), Italy
    "MTY",  // Monterrey, Mexico
    "SVO",  // Moscow (Sheremetyevo), Russia
    "MUC",  // Munich, Germany
    "NGO",  // Nagoya, Japan
    "NBO",  // Nairobi, Kenya
    "NAP",  // Naples, Italy
    "NAS",  // Nassau, Bahamas
    "NCE",  // Nice, France
    "KIX",  // Osaka, Japan
    "OSL",  // Oslo, Norway
    "PTY",  // Panama City, Panama
    "PID",  // Paradise Island, Bahamas
    "CDG",  // Paris (Charles de Gaulle), France
    "ORY",  // Paris (Orly), France
    "PSE",  // Ponce, Puerto Rico
    "PRG",  // Prague, Czech Republic
    "PVR",  // Puerto Vallarta, Mexico
    "RKV",  // Reykjavik, Iceland
    "GIG",  // Rio de Janeiro, Brazil
    "FCO",  // Rome (Leonardo da Vinci/Fiumicino), Italy
    "SJU",  // San Juan, Puerto Rico
    "SCL",  // Santiago de Chile, Chile
    "SDQ",  // Santo Domingo, Dominican Republic
    "GRU",  // Sao Paulo, Brazil
    "CTX",  // Sapporo, Japan
    "SEL",  // Seoul, Korea
    "SNN",  // Shannon, Ireland
    "SIN",  // Singapore
    "STX",  // St. Croix, U.S. Virgin Islands
    "SLU",  // St. Lucia
    "SXM",  // St. Maarten, Netherlands Antilles
    "LED",  // St. Petersburg, Russia
    "STT",  // St. Thomas, U.S. Virgin Islands
    "ARN",  // Stockholm, Sweden
    "STR",  // Stuttgart, Germany
    "SYD",  // Sydney, Australia
    "TPE",  // Taipei, Taiwan
    "TLV",  // Tel Aviv, Israel
    "NRT",  // Tokyo (Narita), Japan
    "EIS",  // Tortola, British Virgin Islands
    "VIE",  // Vienna, Austria
    "WAW",  // Warsaw, Poland
    "XIY",  // Xian Xianyang, China
};
// clang-format on

char *cities[] = {
    "Abilene, Texas",
    "Akron/Canton, Ohio",
    "Albany, New York",
    "Albuquerque, New Mexico",
    "Allentown, Pennsylvania",
    "Amarillo, Texas",
    "Anchorage, Alaska",
    "Appleton, Wisconsin",
    "Atlanta, Georgia",
    "Austin, Texas",
    "Bakersfield, California",
    "Baltimore, Maryland",
    "Bangor, Maine",
    "Baton Rouge, Louisiana",
    "Beaumont/Port Arthur, Texas",
    "Billings, Montana",
    "Birmingham, Alabama",
    "Bloomington, Illinois",
    "Boise, Idaho",
    "Boston, Massachusetts",
    "Buffalo, New York",
    "Burbank, California",
    "Burlington, Vermont",
    "Calgary, Canada",
    "Cedar Rapids, Iowa",
    "Champaign/Urbana, Illinois",
    "Charleston, South Carolina",
    "Charlotte, North Carolina",
    "Chattanooga, Tenessee",
    "Chicago, Illinois (Midway)",
    "Chicago, Illlinois (O'Hare)",
    "Cincinnati, Ohio",
    "Cleveland, Ohio",
    "Colorado Springs, Colorado",
    "Columbia, South Carolina",
    "Columbus, Ohio",
    "Corpus Christi, Texas",
    "Dallas/Fort Worth, Texas",
    "Dayton, Ohio",
    "Denver, Colorado",
    "Des Moines, Iowa",
    "Detroit, Michigan (City)",
    "Detroit, Michigan (Metro)",
    "Dubuque, Iowa",
    "Durango, Colorado",
    "El Paso, Texas",
    "Eugene, Oregon",
    "Evansville, Indiana",
    "Fairbanks, Alaska",
    "Fayetteville, Arkansas",
    "Flint, Michigan",
    "Florence, South Carolina",
    "Fresno, California",
    "Fort Lauderdale, Florida",
    "Fort Myers, Florida",
    "Fort Smith, Arkansas",
    "Fort Walton Beach, Florida",
    "Fort Wayne, Indiana",
    "Grand Rapids, Michigan",
    "Green Bay, Wisconsin",
    "Greeneville/Spartanburg, South Carolina",
    "Greensboro, North Carolina",
    "Gunnison, Colorado",
    "Halifax, Canada",
    "Harlingen, Texas",
    "Harrisburg, Pennsylvania",
    "Hartford, Connecticut",
    "Hilo, Hawaii",
    "Honolulu, Hawaii",
    "Houston, Texas (Hobby)",
    "Houston, Texas (Intercontinental)",
    "Huntsville, Alabama",
    "Indianapolis, Indiana",
    "Islip, New York",
    "Jackson, Mississippi",
    "Jackson Hole, Wyoming",
    "Jacksonville, Florida",
    "Kailua-Kona, Hawaii",
    "Kalamazoo, Michigan",
    "Kansas City, Missouri",
    "Key West, Florida",
    "Knoxville, Tennessee",
    "La Crosse, Wisconsin",
    "Lafayette, Louisiana",
    "Lake Charles, Louisiana",
    "Lansing, Michigan",
    "Las Vegas, Nevada",
    "Lexington, Kentucky",
    "Lihue, Kauai, Hawaii",
    "Lincoln, Nebraska",
    "Little Rock, Arkansas",
    "Long Beach, California",
    "Los Angeles, California",
    "Louisville, Kentucky",
    "Lubbock, Texas",
    "Madison, Wisconsin",
    "Manchester, New Hampshire",
    "Marquette, Michigan",
    "Maui, Hawaii",
    "McAllen, Texas",
    "Medford, Oregon",
    "Melbourne, Florida",
    "Memphis, Tennessee",
    "Miami, Florida",
    "Milwaukee, Wisconsin",
    "Minneapolis, Minnesota",
    "Mobile, Alabama",
    "Moline, Illinois",
    "Molokai, Hawaii",
    "Monterey, California",
    "Montgomery, Alabama",
    "Montréal, Canada",
    "Muskegon, Michigan",
    "Myrtle Beach, South Carolina",
    "Nashville, Tennessee",
    "New Haven, Connecticut",
    "New Orleans, Louisiana",
    "New York, New York (Kennedy)",
    "New York, New York (La Guardia)",
    "Newark, New Jersey",
    "Newburgh/Stewart Field, New York",
    "Newport News, Virginia",
    "Norfolk, Virginia",
    "Oakland, California",
    "Odessa/Midland, Texas",
    "Oklahoma City, Oklahoma",
    "Omaha, Nebraska",
    "Ontario, California",
    "Orange County, California",
    "Orlando, Florida",
    "Ottawa, Canada",
    "Owensboro, Kentucky",
    "Oxnard, California",
    "Palm Springs, California",
    "Pasco, Washington",
    "Pensacola, Florida",
    "Peoria, Illinois",
    "Philadelphia, Pennsylvania",
    "Phoenix, Arizona",
    "Pittsburgh, Pennsylvania",
    "Portland, Maine",
    "Portland, Oregon",
    "Providence, Rhode Island",
    "Quebec, Canada",
    "Raleigh-Durham, North Carolina",
    "Reno, Nevada",
    "Richmond, Virginia",
    "Roanoke, Virginia",
    "Rochester, Minnesota",
    "Rochester, New York",
    "Sacramento, California",
    "Salt Lake City, Utah",
    "San Angelo, Texas",
    "San Antonio, Texas",
    "San Diego, California",
    "San Francisco, California",
    "San Jose, California",
    "Santa Barbara, California",
    "Sarasota, Florida",
    "Savannah, Georgia",
    "Seattle, Washington",
    "Shreveport, Louisiana",
    "Sioux Falls, South Dakota",
    "South Bend, Indiana",
    "Spokane, Washington",
    "Springfield, Illinois",
    "Springfield, Missouri",
    "St. Louis, Missouri",
    "Syracuse, New York",
    "Tallahassee, Florida",
    "Tampa, Florida",
    "Toledo, Ohio",
    "Toronto, Canada",
    "Traverse City, Michigan",
    "Tri City, Tennessee",
    "Tucson, Arizona",
    "Tulsa, Oklahoma",
    "Vail, Colorado",
    "Vancouver, Canada",
    "Waco, Texas",
    "Washington, D.C. (Dulles)",
    "Washington, D.C. (National)",
    "Wausau/Stevens Point, Wisconsin",
    "West Palm Beach, Florida",
    "Westchester County, New York",
    "Wichita, Kansas",
    "Wilmington, North Carolina",
    "Wilkes Barre, Pennsylvania",
    "Abu Dhabi, United Arab Emirates",
    "Acapulco, Mexico",
    "Agana, Guam",
    "Amman, Jordan",
    "Amsterdam, Netherlands",
    "Asuncion, Paraguay",
    "Athens, Greece",
    "Auckland, New Zealand",
    "Bahrain",
    "Bangkok, Thailand",
    "Barcelona, Spain",
    "Beijing, China",
    "Belfast, Northern Ireland, United Kingdom",
    "Belgrade, Yugoslavia",
    "Belize City, Belize",
    "Berlin, Germany",
    "Bimini, Bahamas",
    "Bogota, Columbia",
    "Bombay, India",
    "Bonn, Germany",
    "Brussels, Belgium",
    "Bucharest, Romania",
    "Budapest, Hungary",
    "Buenos Aires, Argentina",
    "Cancun, Mexico",
    "Cape Town, South Africa",
    "Caracas, Venezuela",
    "Casablanca, Morocco",
    "Colombo, Sri Lanka",
    "Cozumel, Mexico",
    "Dominica",
    "Dublin, Ireland",
    "Dusseldorf, Germany",
    "Frankfurt, Germany",
    "Geneva, Switzerland",
    "Glasgow, United Kingdom",
    "Gothenburg, Sweden",
    "Governors Harbour, Bahamas",
    "Guadalajara, Mexico",
    "Guatemala City, Guatemala",
    "Guayaquil, Ecuador",
    "Hamburg, Germany",
    "Hanoi, Vietnam",
    "Helsinki, Finland",
    "Hiroshima, Japan",
    "Hong Kong, China",
    "Huatulco, Mexico",
    "Istanbul, Turkey",
    "Ixtapa, Mexico",
    "Jakarta, Indonesia",
    "Johannesburg, South Africa",
    "Kiev, Ukraine",
    "Kingston, Jamaica",
    "Leon, Mexico",
    "Lima, Peru",
    "Lisbon, Portugal",
    "London (Gatwick), United Kingdom",
    "London (Heathrow), United Kingdom",
    "Los Cabos, Mexico",
    "Lyon, France",
    "Madrid, Spain",
    "Managua, Nicaragua",
    "Manchester, England",
    "Manila, Philippines",
    "Mazatlan, Mexico",
    "Melbourne, Australia",
    "Mexico City, Mexico",
    "Milan (Malpensa), Italy",
    "Monterrey, Mexico",
    "Moscow (Sheremetyevo), Russia",
    "Munich, Germany",
    "Nagoya, Japan",
    "Nairobi, Kenya",
    "Naples, Italy",
    "Nassau, Bahamas",
    "Nice, France",
    "Osaka, Japan",
    "Oslo, Norway",
    "Panama City, Panama",
    "Paradise Island, Bahamas",
    "Paris (Charles de Gaulle), France",
    "Paris (Orly), France",
    "Ponce, Puerto Rico",
    "Prague, Czech Republic",
    "Puerto Vallarta, Mexico",
    "Reykjavik, Iceland",
    "Rio de Janeiro, Brazil",
    "Rome (Leonardo da Vinci/Fiumicino), Italy",
    "San Juan, Puerto Rico",
    "Santiago de Chile, Chile",
    "Santo Domingo, Dominican Republic",
    "Sao Paulo, Brazil",
    "Sapporo, Japan",
    "Seoul, Korea",
    "Shannon, Ireland",
    "Singapore",
    "St. Croix, U.S. Virgin Islands",
    "St. Lucia",
    "St. Maarten, Netherlands Antilles",
    "St. Petersburg, Russia",
    "St. Thomas, U.S. Virgin Islands",
    "Stockholm, Sweden",
    "Stuttgart, Germany",
    "Sydney, Australia",
    "Taipei, Taiwan",
    "Tel Aviv, Israel",
    "Tokyo (Narita), Japan",
    "Tortola, British Virgin Islands",
    "Vienna, Austria",
    "Warsaw, Poland",
    "Xian Xianyang, China",
};
